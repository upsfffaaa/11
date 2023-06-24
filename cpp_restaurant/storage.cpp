#include <iostream>
#include <vector>

#include "Accounting.h"
#include "FileActions.h"
#include "Application.h"

class storage {
public:
	void Storage() {

		bool isChoosingIngredient = true;

		GetValues getValues;

		std::vector<Accounting> accountings = getValues.getAccounting();
		std::vector<Ingredient> ingredients = getValues.getIngridients();
		std::vector<Application> applications = getValues.getApplications();

		while (isChoosingIngredient) {

			system("cls");

			std::cout << "�����" << std::endl;

			int sum = 0;
			float balance = 0;
			std::string status = "��������";

			for (const auto& accounting : accountings) {
				balance = accounting.balance;
				std::cout << "�� ����� : " << accounting.balance << std::endl;
			}

			std::cout << "�������� ���������� ��� ������ (0 ��� ���������� ������) : " << std::endl;

			for (const auto& ingredient : ingredients) {

				std::cout << ingredient.id << " | " << ingredient.name << " " << ingredient.type << " " << ingredient.count
					<< " " << ingredient.cost << std::endl;
			}

			int ingredientChoice, count;

			std::cin >> ingredientChoice;

			std::vector<Ingredient> currIngredients;
			std::vector<Application> currApplication;

			if (ingredientChoice <= ingredients.size() && ingredientChoice > 0) {
				Ingredient ingredient = ingredients[ingredientChoice - 1];

				//���� ��������
				std::cout << "� ����� ���������� ��������?" << std::endl;

				std::cin >> count;

				//��������� �������� ingredient
				ingredient.count = count;

				sum += ingredient.cost * ingredient.count;

				currIngredients.clear();

				currIngredients.push_back(ingredient);

				Application application(applications.size()+1, currIngredients, status, sum);

				currApplication.push_back(application);

				if (balance >= sum) {
					std::string fileName = "applications.txt";

					//������� ����
					std::ofstream file(fileName, std::ostream::app);

					//������� � ���� ��������
					for (const auto& data : currApplication) {
						file << application.id << "-";
						for (const auto& ingridient : currIngredients) {
							file << ingridient.id;
						}
						file << "-" << data.status << "-" << data.sum << "\n";
					}


					//��������� ����
					file.close();


				}
				else {
					std::cout << "������������ �������." << std::endl;
				}

				applications.clear();
				currIngredients.clear();
				sum = 0;
			}
			else if (ingredientChoice == 0) {
				isChoosingIngredient = false;
			}
		}
	}
};