#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include <iomanip>
#include <sstream>
#include <ctime>

#include "FileLogic.h"
#include "Dish.h"
#include "Ingredient.h"
#include "Order.h"
#include "FileActions.h"

class GuestWindow {
public:
	void Guest() {
		while (true) {

			system("cls");

			std::cout << "����:" << std::endl;

			FileLogic fileLogic;

			int answer = 0;
			std::vector<Ingredient> ingredients;

			GetValues getValues;

			std::vector<Dish> dishes = getValues.getDishes();

			for (const auto& dish : dishes) {

				long long minutes = dish.preptime.count();
				std::string timeString = std::to_string(minutes);

				std::cout << dish.id << " | " << dish.name << ", ���: " << dish.weight << " �����, ��������: " << dish.description
					<< ", ����� �������������: " << timeString
					<< ", ����: " << dish.cost << std::endl;
			}


			bool isOrder = true;

			float sum = 0;

			std::vector<Dish> currDishes;

			while (isOrder) {

				std::cout << "�������� �����. (0 - ���� ������� �������� �����)" << std::endl;

				std::cin >> answer;

				if (answer <= dishes.size() && answer > 0) {
					sum += dishes[answer - 1].cost;

					currDishes.push_back(dishes[answer - 1]);
				}
				else if (answer == 0) {
					isOrder = false;
					std::cout << "��������� �����..." << std::endl;
				}
				else {
					std::cout << "�������� ����� �����" << std::endl;
				}
			}

			std::string fileName = "orders.txt";

			std::vector<Order> orders = getValues.getOrders();

			int id = 0;

			for (const auto& order : orders) {
				id = order.id;
			}

			Order order = { id + 1, currDishes, "������� � ������� �� �����", sum };

			//������� ����
			std::ofstream file(fileName, std::ofstream::app);

			std::vector<Order> newOrder;
			newOrder.push_back(order);

			//������� � ���� ��������
			for (const auto& data : newOrder) {
				file << data.id << "-";
				for (const auto& dish : currDishes) {
					file << dish.id;
				}
				file << "-" << data.status << "-" << data.sum << " \n";
			}

			//��������� ����
			file.close();

			std::vector<Accounting> accountings = getValues.getAccounting();

			fileName = "accounting.txt";

			orders = getValues.getOrders();

			//������� ����
			std::ofstream file1(fileName);

			//������� � ���� ��������
			for (const auto& data : accountings) {
				file1 << data.balance + sum << "-";
				for (const auto& order : orders) {
					file1 << order.id;
				}
				file1 << "-" << data.globalSum + sum << "-" << data.totalPurchase << " \n";
			}

			//��������� ����
			file1.close();

			fileName = "activities.txt";

			std::vector<GuestActivity> guestActivities = getValues.getActivities();

			//������� ����
			std::ofstream file2(fileName, std::ofstream::app);

			std::string currentDateTime = getCurrentDateTimeAsString();

			GuestActivity guestActivity(guestActivities.size() + 1, "���������� ������", currentDateTime);

			guestActivities.push_back(guestActivity);

			//������� � ���� ��������
			for (const auto& data : guestActivities) {
				file2 << data.id << "~" << data.description << "~" << data.time << "\n";
			}

			//��������� ����
			file2.close();

			std::cout << "����� �������� � ������� �� �����." << std::endl;

			// �������� �� �������
			std::this_thread::sleep_for(std::chrono::seconds(1));
		}
		
	}

	std::string getCurrentDateTimeAsString() {
		// �������� ������� ����� � ���� �������
		std::time_t currentTime = std::time(nullptr);

		// ����������� ����� � ���� � ��������� tm
		std::tm localTime;
		localtime_s(&localTime, &currentTime);

		// ����������� ����� � ���� � ������
		char buffer[20];
		std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", &localTime);

		return std::string(buffer);
	}

};