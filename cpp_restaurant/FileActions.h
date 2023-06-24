#ifndef FILEACTIONS_H
#define FILEACTIONS_H

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <ctime>
#include <algorithm>

#include "Ingredient.h"
#include "Dish.h"
#include "Order.h"
#include "User.h"
#include "Accounting.h"
#include "Application.h"
#include "GuestActivity.h"

class GetValues {
public:
	std::vector<Ingredient> getIngridients() {

		std::vector<Ingredient> ingredients;

		//Считываем файл с ингредиентами
		std::ifstream file("ingredients.txt");
		if (file.is_open()) {
			std::string line;
			while (std::getline(file, line)) {
				std::stringstream ss(line);
				std::string item;
				std::vector<std::string> values;

				//Считываем ингредиенты из файла
				while (std::getline(ss, item, '-')) {
					values.push_back(item);
				}

				//Когда считали 5 параметров ингредиента, записываем их в вектор
				if (values.size() == 5) {
					int id = std::stoi(values[0]);
					std::string name = values[1];
					std::string type = values[2];
					int count = std::stoi(values[3]);
					float cost = std::stof(values[4]);

					ingredients.push_back(Ingredient(id, name, type, count, cost));
				}
			}

			//Закрываем файл
			file.close();

			return ingredients;
		}
		else {
			std::cout << "Не удалось открыть файл ingredients.txt." << std::endl;
		}
	}

	std::vector<Dish> getDishes() {

		std::vector<Dish> dishes;

		//Считываем файл с блюдами
		std::ifstream file("dishes.txt");
		if (file.is_open()) {
			std::string line;
			while (std::getline(file, line)) {
				std::stringstream ss(line);
				std::string item;
				std::vector<std::string> values;

				//Считываем блюда из файла
				while (std::getline(ss, item, '-')) {
					values.push_back(item);
				}

				//Когда считали 7 параметров блюда, выводим их пользователю
				if (values.size() == 7) {
					int id = std::stoi(values[0]);
					std::string name = values[1];
					float weight = std::stof(values[2]);
					std::string ingridientsIds = values[3];
					std::string description = values[4];
					int minutes = std::stoi(values[5]);
					float cost = std::stof(values[6]);

					GetValues getValues;

					std::vector<Ingredient> ingredients = getValues.getIngridients();

					std::vector<Ingredient> currIngredients;

					for (const auto& ingredient : ingredients) {
						int i = 1;
						while (i <= ingridientsIds.length()) {
							if (i < 9) {
								if (ingredient.id == ingridientsIds[i-1] - '0') {
									currIngredients.push_back(Ingredient(ingredient.id, ingredient.name, ingredient.type, ingredient.count, ingredient.cost));
								}
								i++;
							}
							else {
								if (ingredient.id == ((ingridientsIds[i-2] - '0') * 10 + ingridientsIds[i-1] - '0')) {
									currIngredients.push_back(Ingredient(ingredient.id, ingredient.name, ingredient.type, ingredient.count, ingredient.cost));
								}
								i+=2;
							}
						}
					}

					std::chrono::minutes preptime(minutes);

					dishes.push_back(Dish(id, name, weight, currIngredients, description, preptime, cost));
				}
			}

			//Закрываем файл
			file.close();

			return dishes;
		}
		else {
			std::cout << "Не удалось открыть файл dishes.txt." << std::endl;
		}
	}

	std::vector<Order> getOrders() {

		GetValues getValues;

		std::vector<Order> orders;

		std::vector<Dish> dishes = getValues.getDishes();

		std::ifstream file("orders.txt");
		if (file.is_open()) {
			std::string line;
			while (std::getline(file, line)) {
				std::stringstream ss(line);
				std::string item;
				std::vector<std::string> values;

				//Считываем блюда из файла
				while (std::getline(ss, item, '-')) {
					values.push_back(item);
				}

				std::vector<Dish> currDishes;

				//Когда считали 4 параметра заказа, записываем их в вектор
				if (values.size() == 4) {
					int id = std::stoi(values[0]);
					std::string dishesIds = values[1];
					std::string status = values[2];
					float sum = std::stof(values[3]);

					for (const auto& dish : dishes) {
						int i = 1;
						while (i <= dishesIds.length()) {
							if (i < 9) {
								if (dish.id == dishesIds[i - 1] - '0') {
									currDishes.push_back(Dish(dish.id, dish.name, dish.weight, dish.ingridients, dish.description, dish.preptime, dish.cost));
								}
								i++;
							}
							else {
								if (dish.id == ((dishesIds[i - 2] - '0') * 10  + dishesIds[i - 1] - '0')) {
									currDishes.push_back(Dish(dish.id, dish.name, dish.weight, dish.ingridients, dish.description, dish.preptime, dish.cost));
								}
								i += 2;
							}
						}
					}

					orders.push_back(Order(id, currDishes, status, sum));
				}
			}

			//Закрываем файл
			file.close();

			return orders;
		}
		else {
			std::cout << "Не удалось открыть файл orders.txt." << std::endl;
		}
	}

	std::vector<User> getUsers() {

		std::vector<User> users;

		//Считываем файл с пользователями
		std::ifstream file("users.txt");
		if (file.is_open()) {
			std::string line;
			while (std::getline(file, line)) {
				std::stringstream ss(line);
				std::string item;
				std::vector<std::string> values;

				//Считываем пользователей из файла
				while (std::getline(ss, item, '-')) {
					values.push_back(item);
				}

				//Когда считали 7 параметров пользователя, записываем их в вектор
				if (values.size() == 7) {
					int id = std::stoi(values[0]);
					std::string surname = values[1];
					std::string name = values[2];
					std::string patronymic = values[3];
					std::string login = values[4];
					std::string password = values[5];
					std::string role = values[6];
					users.push_back(User(id, surname, name, patronymic, login, password, role));
				}
			}

			//Закрываем файл
			file.close();

			return users;
		}
		else {
			std::cout << "Не удалось открыть файл users.txt." << std::endl;
		}
	}

	std::vector<Accounting> getAccounting() {

		std::vector<Accounting> accountings;

		GetValues getValues;

		std::vector<Order> orders = getValues.getOrders();

		//Считываем файл с учетом
		std::ifstream file("accounting.txt");
		if (file.is_open()) {
			std::string line;
			while (std::getline(file, line)) {
				std::stringstream ss(line);
				std::string item;
				std::vector<std::string> values;

				//Считываем учет из файла
				while (std::getline(ss, item, '-')) {
					values.push_back(item);
				}

				//Когда считали 4 параметра учета, записываем их в вектор
				if (values.size() == 4) {
					float balance = std::stof(values[0]);
					float globalSum = std::stof(values[2]);
					float totalPurchase = std::stof(values[3]);

					accountings.push_back(Accounting(balance, orders, globalSum, totalPurchase));
				}
			}

			//Закрываем файл
			file.close();

			return accountings;
		}
		else {
			std::cout << "Не удалось открыть файл accounting.txt." << std::endl;
		}
	}

	std::vector<GuestActivity> getActivities() {
		
		std::vector<GuestActivity> guestActivities;

		//Считываем файл с учетом
		std::ifstream file("activities.txt");
		if (file.is_open()) {
			std::string line;
			while (std::getline(file, line)) {
				std::stringstream ss(line);
				std::string item;
				std::vector<std::string> values;

				//Считываем учет из файла
				while (std::getline(ss, item, '~')) {
					values.push_back(item);
				}

				//Когда считали 3 параметра учета, записываем их в вектор
				if (values.size() == 3) {
					int id = std::stoi(values[0]);
					std::string description = values[1];
					std::string time = values[2];

					guestActivities.push_back(GuestActivity(id, description, time));
				}
			}

			//Закрываем файл
			file.close();

			return guestActivities;
		}
		else {
			std::cout << "Не удалось открыть файл activities.txt." << std::endl;
		}
	}

	std::vector<Application> getApplications() {

		std::vector<Application> applications;

		GetValues getValues;

		std::vector<Ingredient> ingredients = getValues.getIngridients();

		//Считываем файл
		std::ifstream file("applications.txt");
		if (file.is_open()) {
			std::string line;
			while (std::getline(file, line)) {
				std::stringstream ss(line);
				std::string item;
				std::vector<std::string> values;

				//Считываем из файла
				while (std::getline(ss, item, '-')) {
					values.push_back(item);
				}

				//Когда считали 4 параметра, записываем их в вектор
				if (values.size() == 4) {
					int id = std::stoi(values[0]);
					std::string ingredientsIds = values[1];
					std::string status = values[2];
					float sum = std::stof(values[3]);

					std::vector<Ingredient> currIngredients;

					for (const auto& ingredient : ingredients) {
						for (int i = 1; i <= ingredientsIds.length(); i++) {
							if (ingredient.id == (ingredientsIds[i - 1] - '0')) {
								currIngredients.push_back(ingredient);
							}
						}
					}

					applications.push_back(Application(id, currIngredients, status, sum));
				}
			}

			//Закрываем файл
			file.close();

			return applications;
		}
		else {
			std::cout << "Не удалось открыть файл applications.txt." << std::endl;
		}
	}
};

class SetValues {
public:
	void setOrderStatus(int answer, std::string status) {

		GetValues getValues;

		std::vector<Order> orders = getValues.getOrders();

		if (answer <= orders.size() && answer > 0) {
			Order order = orders[answer - 1];

			//удаление из вектора
			orders.erase(std::remove_if(orders.begin(), orders.end(), [&](const Order& u) { return u.id == order.id; }), orders.end());

			order.status = status;

			orders.push_back(order);

			//сортировка вектора по значению id
			std::sort(orders.begin(), orders.end(), [](const Order& o1, const Order& o2) {
				return o1.id < o2.id;
				});

			std::string fileName = "orders.txt";

			//создаем файл
			std::ofstream file(fileName);

			//заносим в него значения
			for (const auto& data : orders) {
				file << data.id << "-";
				for (const auto& dish : data.dishes) {
					file << dish.id;
				}
				file << "-" << data.status << "-" << data.sum << " \n";
			}

			//закрываем файл
			file.close();
		}
	}
};

#endif