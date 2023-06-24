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

			std::cout << "Окно повара" << std::endl;

			GetValues getValues;

			std::vector<Order> orders = getValues.getOrders();


			std::cout << "Заказы : " << std::endl;

			for (const auto& order : orders) {
				if (order.status == "Оплачен и передан на кухню") {
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

			std::cout << "\nВыберите заказ для приготовления : ";

			int answer;

			std::cin >> answer;

			SetValues setValues;

			setValues.setOrderStatus(answer, "В процессе приготовления");

			std::cout << "\nЗавершить приготовление заказа? (0 - нет, 1 - да) : ";

			int answer1;

			std::cin >> answer1;

			if (answer1 == 1) {
				setValues.setOrderStatus(answer, "Передан официанту на выдачу");
			}
			else if (answer1 != 1) {
				std::cout << "\nНеверное действие, ПОКА";
				break;
			}
		}

		
	}
};