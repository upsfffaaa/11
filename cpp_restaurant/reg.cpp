#include <iostream>
#include <vector>
#include "Application.h"
#include "FileActions.h"

class reg {
public:
	void Accountant() {

		system("cls");

		std::cout << "���� ����������" << std::endl;

		std::cout << "�������� �������� : " << "\n"
			<< "1 - ����������� ������ �� ��������;" << "\n"
			<< "2 - ����������� ���������� ����������;" << "\n";

		int answer;

		std::cin >> answer;

		GetValues getValues;

		std::vector<Application> applications = getValues.getApplications();
		std::vector<Accounting> accountings = getValues.getAccounting();

		switch (answer)
		{
		case 1:

			system("cls");

			std::cout << "������ �� �������� : " << std::endl;

			for (const auto& application : applications) {
				std::cout << application.id << " | ";
				for (const auto& ingredient : application.ingredients) {
					std::cout << ingredient.name << " " << ingredient.type << " " << ingredient.count << " " << ingredient.cost;
				}
				std::cout << " " << application.status << " �� ����� : " << application.sum << std::endl;

			}

			break;
		case 2:

			system("cls");

			std::cout << "���������� ���������� : " << std::endl;

			for (const auto& accounting : accountings) {
				std::cout << "������ : " << accounting.balance << "\n";
				for (const auto& order : accounting.orders) {
					std::cout << order.id << " " << order.status << " " << order.sum << "\n";
				}
				std::cout << "����� ����� ������� : " << accounting.globalSum << "\n����� ����� ������ �� ����������� : " << accounting.totalPurchase << std::endl;

			}

			break;
		default:
			std::cout << "�������� ��������, ����";
			break;
		}
	}
};