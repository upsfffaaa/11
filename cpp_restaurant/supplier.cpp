#include <iostream>
#include <vector>
#include "Application.h"
#include "FileActions.h"
#include <algorithm>

class supplier {
public:
	void Supplier() {

		bool isChoosingApplication = true;

		while (isChoosingApplication) {

			system("cls");

			std::cout << "Окно поставщика" << std::endl;

			GetValues getValues;

			std::vector<Application> applications = getValues.getApplications();
			std::vector<Accounting> accountings = getValues.getAccounting();

			std::cout << "Выберите заявку для подтверждения (0 для завершения) : " << std::endl;

			for (const auto& application : applications) {

				if (application.status == "Заказано") {
					std::cout << application.id << " | ";
					for (const auto& ingredient : application.ingredients) {
						std::cout << ingredient.name << " " << ingredient.type << " " << ingredient.count << " " << ingredient.cost;
					}
					std::cout << " " << application.status << " на сумму : " << application.sum << std::endl;
				}
			}

			int applicationChoice, count;

			std::cin >> applicationChoice;

			if (applicationChoice <= applications.size() && applicationChoice > 0) {
				Application application = applications[applicationChoice - 1];

				std::vector<Ingredient> currIngredients = application.ingredients;

				//удаление ингредиента из вектора
				applications.erase(std::remove_if(applications.begin(), applications.end(), [&](const Application& u) { return u.id == application.id; }), applications.end());

				application.status = "Отправлено.";

				applications.push_back(application);

				//сортировка вектора по значению id
				std::sort(applications.begin(), applications.end(), [](const Application& a1, const Application& a2) {
					return a1.id < a2.id;
					});

				std::string fileName = "applications.txt";

				//создаем файл
				std::ofstream file(fileName);

				//заносим в него значения
				for (const auto& data : applications) {
					file << data.id << "-";
					for (const auto& ingridient : currIngredients) {
						file << ingridient.id;
					}
					file << "-" << data.status << "-" << data.sum << "\n";
				}

				//закрываем файл
				file.close();

				std::vector<Order> orders;
				float balance = 0, globalSum, totalPurchase = 0;


				for (const auto& accounting : accountings) {
					balance = accounting.balance;
					orders = accounting.orders;
					globalSum = accounting.globalSum;
					totalPurchase = accounting.totalPurchase;
				}

				balance -= application.sum;
				totalPurchase += application.sum;

				Accounting accounting(balance, orders, globalSum, totalPurchase);

				accountings.clear();
				accountings.push_back(accounting);

				fileName = "accounting.txt";

				//создаем файл
				std::ofstream file1(fileName);

				//заносим в него значения
				for (const auto& data : accountings) {
					file1 << data.balance << "-";
					for (const auto& order : orders) {
						file1 << order.id;
					}
					file1 << "-" << data.globalSum << "-" << data.totalPurchase << "\n";
				}

				//закрываем файл
				file1.close();

				std::vector<Ingredient> ingredients = getValues.getIngridients();

				for (const auto& currIngredient : currIngredients) {
					
					Ingredient ingredient = ingredients[currIngredient.id-1];

					//удаление ингредиента из вектора
					ingredients.erase(std::remove_if(ingredients.begin(), ingredients.end(), [&](const Ingredient& u) { return u.id == ingredient.id; }), ingredients.end());

					ingredient.count += currIngredient.count;

					ingredients.push_back(ingredient);

					//сортировка вектора по значению id
					std::sort(ingredients.begin(), ingredients.end(), [](const Ingredient& i1, const Ingredient& i2) {
						return i1.id < i2.id;
						});


					std::string fileName = "ingredients.txt";

					//создаем файл
					std::ofstream file(fileName);

					//заносим в него значения
					for (const auto& data : ingredients) {
						file << data.id << "-" << data.name << "-" << data.type << "-" << data.count << "-" << data.cost << "\n";
					}

					//закрываем файл
					file.close();

				}
			}
			else if (isChoosingApplication == 0) {
				isChoosingApplication = false;
			}
		}
	}
};