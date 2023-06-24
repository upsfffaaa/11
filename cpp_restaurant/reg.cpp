#include <iostream>
#include <vector>
#include "Application.h"
#include "FileActions.h"

class reg {
public:
	void Accountant() {

		system("cls");

		std::cout << "Окно бухгалтера" << std::endl;

		std::cout << "Выберите действие : " << "\n"
			<< "1 - Просмотреть заявки на продукты;" << "\n"
			<< "2 - Просмотреть финансовую отчетность;" << "\n";

		int answer;

		std::cin >> answer;

		GetValues getValues;

		std::vector<Application> applications = getValues.getApplications();
		std::vector<Accounting> accountings = getValues.getAccounting();

		switch (answer)
		{
		case 1:

			system("cls");

			std::cout << "Заявки на продукты : " << std::endl;

			for (const auto& application : applications) {
				std::cout << application.id << " | ";
				for (const auto& ingredient : application.ingredients) {
					std::cout << ingredient.name << " " << ingredient.type << " " << ingredient.count << " " << ingredient.cost;
				}
				std::cout << " " << application.status << " на сумму : " << application.sum << std::endl;

			}

			break;
		case 2:

			system("cls");

			std::cout << "Финансовая отчетность : " << std::endl;

			for (const auto& accounting : accountings) {
				std::cout << "Баланс : " << accounting.balance << "\n";
				for (const auto& order : accounting.orders) {
					std::cout << order.id << " " << order.status << " " << order.sum << "\n";
				}
				std::cout << "Общая сумма заказов : " << accounting.globalSum << "\nОбщая сумма затрат на ингредиенты : " << accounting.totalPurchase << std::endl;

			}

			break;
		default:
			std::cout << "Неверное действие, ПОКА";
			break;
		}
	}
};