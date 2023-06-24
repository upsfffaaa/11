#include <iostream>
#include <string>
#include <vector>

#include "FileActions.h"
#include "User.h"
#include "gostb.cpp"
#include "admin.cpp"
#include "storage.cpp"
#include "supplier.cpp"
#include "reg.cpp"
#include "povar.cpp"
#include "rab.cpp"

class aut {
public:
	void Auth() {

		int answer;

		std::cout << "Добро пожаловать в ресторан." << "\n"
			<< "Желаете авторизоваться или войти как гость?" << "\n"
			<< "0 - Авторизация;" << "\n"
			<< "1 - Войти как гость." << std::endl;
		std::cin >> answer;

		std::string login, password;

		GetValues getValues;
		//Вектор для пользователей
		std::vector<User> users = getValues.getUsers();

		switch (answer)
		{
		case 0:

			std::cout << "Введите логин: ";
			std::cin >> login;
			std::cout << "Введите пароль: ";
			std::cin >> password;

			for (const auto& user : users) {
				if (user.login == login && user.password == password) {
					//Если находит пользователя с таким логином и паролем, проходит авторизацию по роли и перекидывает на нужное окно
					if (user.role == "admin") {
						admin admin;
						admin.Admin();
					}
					else if (user.role == "storage") {
						storage storage;
						storage.Storage();
					}
					else if (user.role == "supplier") {
						supplier supplier;
						supplier.Supplier();
					}
					else if (user.role == "accountant") {
						reg accountant;
						accountant.Accountant();
					}
					else if (user.role == "chef") {
						povar chef;
						chef.Chef();
					}
					else if (user.role == "officiant") {
						rab officiant;
						officiant.Officiant();
					}
				}
				else {
					std::cout << "Неверный логин или пароль, ПОКА";
				}
			}
			break;
		case 1:
			//Перенос в окно гостя
			GuestWindow guest;
			guest.Guest();
			break;
		default:
			break;
		}
	}
};