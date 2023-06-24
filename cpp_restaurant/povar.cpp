#include <iostream>
#include <vector>
#include <algorithm>

#include "Order.h"
#include "FileActions.h"

class povar {
public:
	void Chef() {

		while (true) {

			system("cls");

			std::cout << "���� ������" << std::endl;

			GetValues getValues;

			std::vector<Order> orders = getValues.getOrders();


			std::cout << "������ : " << std::endl;

			for (const auto& order : orders) {
				if (order.status == "������� � ������� �� �����") {
					std::cout << order.id << " : \n";
					for (const auto& dish : order.dishes) {
						long long minutes = dish.preptime.count();
						std::string timeString = std::to_string(minutes);
						std::cout << dish.name << " " << dish.weight << " " << dish.description << " " << timeString << " " << dish.cost << "\n";
						for (const auto& ingredient : dish.ingridients) {
							std::cout << " - " << ingredient.name << " " << ingredient.type << " " << ingredient.count << " " << ingredient.cost << "\n";
						}
					}
				}
			}

			std::cout << "\n�������� ����� ��� ������������� : ";

			int answer;

			std::cin >> answer;

			SetValues setValues;

			setValues.setOrderStatus(answer, "� �������� �������������");

			std::cout << "\n��������� ������������� ������? (0 - ���, 1 - ��) : ";

			int answer1;

			std::cin >> answer1;

			if (answer1 == 1) {
				setValues.setOrderStatus(answer, "������� ��������� �� ������");
			}
			else if (answer1 != 1) {
				std::cout << "\n�������� ��������, ����";
				break;
			}
		}

		
	}
};