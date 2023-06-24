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

		std::cout << "����� ���������� � ��������." << "\n"
			<< "������� �������������� ��� ����� ��� �����?" << "\n"
			<< "0 - �����������;" << "\n"
			<< "1 - ����� ��� �����." << std::endl;
		std::cin >> answer;

		std::string login, password;

		GetValues getValues;
		//������ ��� �������������
		std::vector<User> users = getValues.getUsers();

		switch (answer)
		{
		case 0:

			std::cout << "������� �����: ";
			std::cin >> login;
			std::cout << "������� ������: ";
			std::cin >> password;

			for (const auto& user : users) {
				if (user.login == login && user.password == password) {
					//���� ������� ������������ � ����� ������� � �������, �������� ����������� �� ���� � ������������ �� ������ ����
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
					std::cout << "�������� ����� ��� ������, ����";
				}
			}
			break;
		case 1:
			//������� � ���� �����
			GuestWindow guest;
			guest.Guest();
			break;
		default:
			break;
		}
	}
};