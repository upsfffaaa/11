#include <iostream>
#include <vector>
#include <algorithm>

#include "User.h"
#include "FileActions.h"


class admin {
public:
	int idUser;
	void Admin() {

		system("cls");

		std::cout << "���� ��������������." << "\n"
			<< "�������� ��������: " << "\n"
			<< "1 - ��������������� ������������;" << "\n"
			<< "2 - �������� ����������;" << "\n"
			<< "3 - �������� ����������;" << "\n"
			<< "4 - ������� ����������;" << "\n"
			<< "5 - �������� �����;" << "\n"
			<< "6 - �������� �����;" << "\n"
			<< "7 - ������� �����;" << "\n"
			<< "8 - ������ ���������� �����." << std::endl;

		int choice;

		std::cin >> choice;

		GetValues getValues;
		std::vector<User> users = getValues.getUsers();
		std::vector<Ingredient> ingredients = getValues.getIngridients();
		std::vector<Dish> dishes = getValues.getDishes();
		std::vector<GuestActivity> guestActivities = getValues.getActivities();

		std::string surname;
		std::string name;
		std::string patronymic;
		std::string login;
		std::string password;

		std::string nameIngredient;
		std::string typeIngredient;
		int countIngredient;
		float costIngredient;

		std::string nameDish;
		float weightDish;
		std::vector<Ingredient> ingridientsDish;
		std::string descriptionDish;
		int minutes;
		float costDish;

		bool isChangingUser, isAddingIngredient, isChangingIngredient, isDeletingIngredient, isAddingDish, isChangingDish, isDeletingDish, isCheckingActivity;

		switch (choice)
		{
		case 1:
			isChangingUser = true;

			while (isChangingUser) {

				system("cls");

				std::cout << "�������� ������������ (��� 0, ����� �����) : " << std::endl;

				for (const auto& user : users) {

					std::cout << user.id << " | " << user.surname << " " << user.name << " " << user.patronymic
						<< " " << user.login
						<< " " << user.password << std::endl;
				}

				int userChoice;

				std::cin >> userChoice;

				if (userChoice <= users.size() && userChoice > 0) {
					User user = users[userChoice - 1];

					//���� ��������
					std::cout << "������� ������� : ";
					std::cin >> surname;
					std::cout << "������� ��� : ";
					std::cin >> name;
					std::cout << "������� �������� : ";
					std::cin >> patronymic;
					std::cout << "������� ����� : ";
					std::cin >> login;
					std::cout << "������� ������ : ";
					std::cin >> password;

					//�������� ������������ �� �������
					users.erase(std::remove_if(users.begin(), users.end(), [&](const User& u) { return u.id == user.id; }), users.end());

					//��������� �������� user
					user.surname = surname;
					user.name = name;
					user.patronymic = patronymic;
					user.login = login;
					user.password = password;

					users.push_back(user);

					//���������� ������� �� �������� id
					std::sort(users.begin(), users.end(), [](const User& u1, const User& u2) {
						return u1.id < u2.id;
						});


					std::string fileName = "users.txt";

					//������� ����
					std::ofstream file(fileName);

					//������� � ���� ��������
					for (const auto& data : users) {
						file << data.id << "-" << data.surname << "-" << data.name << "-" << data.patronymic << "-" << data.login << "-" << data.password << "-" << data.role << "\n";
					}

					//��������� ����
					file.close();
				}
				else if (userChoice == 0) {
					isChangingUser = false;
				}
			}


			break;
		case 2:
			isAddingIngredient = true;

			while (isAddingIngredient) {

				system("cls");

				std::cout << "������� �������� ����������� : ";
				std::cin >> nameIngredient;
				std::cout << "������� ��� ����������� : ";
				std::cin >> typeIngredient;
				std::cout << "������� ���������� ����������� : ";
				std::cin >> countIngredient;
				std::cout << "������� ��������� ����������� : ";
				std::cin >> costIngredient;

				Ingredient ingredient(ingredients.size() + 1, nameIngredient, typeIngredient, countIngredient, costIngredient);

				ingredients.push_back(ingredient);


				std::string fileName = "ingredients.txt";
				//������� ����
				std::ofstream file(fileName);

				//������� � ���� ��������
				for (const auto& data : ingredients) {
					file << data.id << "-" << data.name << "-" << data.type << "-" << data.count << "-" << data.cost << "\n";
				}

				//��������� ����
				file.close();
			}

			break;
		case 3:

			isChangingIngredient = true;

			while (isChangingIngredient) {

				system("cls");

				std::cout << "�������� ���������� (��� 0, ����� �����) : " << std::endl;

				for (const auto& ingredient : ingredients) {

					std::cout << ingredient.id << " | " << ingredient.name << " " << ingredient.type << " " << ingredient.count
						<< " " << ingredient.cost << std::endl;
				}

				int ingredientChoice;

				std::cin >> ingredientChoice;

				if (ingredientChoice <= ingredients.size() && ingredientChoice > 0) {
					Ingredient ingredient = ingredients[ingredientChoice - 1];

					//���� ��������
					std::cout << "������� �������� : ";
					std::cin >> nameIngredient;
					std::cout << "������� ��� : ";
					std::cin >> typeIngredient;
					std::cout << "������� ���������� : ";
					std::cin >> countIngredient;
					std::cout << "������� ���� : ";
					std::cin >> costIngredient;

					//�������� ����������� �� �������
					ingredients.erase(std::remove_if(ingredients.begin(), ingredients.end(), [&](const Ingredient& u) { return u.id == ingredient.id; }), ingredients.end());

					//��������� �������� ingredient
					ingredient.name = nameIngredient;
					ingredient.type = typeIngredient;
					ingredient.count = countIngredient;
					ingredient.cost = costIngredient;

					ingredients.push_back(ingredient);

					//���������� ������� �� �������� id
					std::sort(ingredients.begin(), ingredients.end(), [](const Ingredient& i1, const Ingredient& i2) {
						return i1.id < i2.id;
						});


					std::string fileName = "ingredients.txt";

					//������� ����
					std::ofstream file(fileName);

					//������� � ���� ��������
					for (const auto& data : ingredients) {
						file << data.id << "-" << data.name << "-" << data.type << "-" << data.count << "-" << data.cost << "\n";
					}

					//��������� ����
					file.close();
				}
				else if (ingredientChoice == 0) {
					isChangingIngredient = false;
				}
			}

			break;

		case 4:

			isDeletingIngredient = true;

			while (isDeletingIngredient) {
				system("cls");

				std::cout << "�������� ���������� (��� 0, ����� �����) : " << std::endl;

				for (const auto& ingredient : ingredients) {

					std::cout << ingredient.id << " | " << ingredient.name << " " << ingredient.type << " " << ingredient.count
						<< " " << ingredient.cost << std::endl;
				}

				int ingredientChoice;

				std::cin >> ingredientChoice;

				if (ingredientChoice <= ingredients.size() && ingredientChoice > 0) {
					Ingredient ingredient = ingredients[ingredientChoice - 1];

					//�������� ����������� �� �������
					ingredients.erase(std::remove_if(ingredients.begin(), ingredients.end(), [&](const Ingredient& u) { return u.id == ingredient.id; }), ingredients.end());

					//���������� ������� �� �������� id
					std::sort(ingredients.begin(), ingredients.end(), [](const Ingredient& i1, const Ingredient& i2) {
						return i1.id < i2.id;
						});


					std::string fileName = "ingredients.txt";

					//������� ����
					std::ofstream file(fileName);

					//������� � ���� ��������
					for (const auto& data : ingredients) {
						file << data.id << "-" << data.name << "-" << data.type << "-" << data.count << "-" << data.cost << "\n";
					}

					//��������� ����
					file.close();
				}
				else if (ingredientChoice == 0) {
					isChangingIngredient = false;
				}
			}

			break;
		case 5:

			isAddingDish = true;

			while (isAddingDish) {

				system("cls");

				std::cout << "������� �������� ����� : ";
				std::cin >> nameDish;
				std::cout << "������� ��� ����� : ";
				std::cin >> weightDish;
				std::cout << "������� ����������� ����� : ";

				int choiceIngredient;
				bool isAdding = true;

				std::vector<Ingredient> currIngredients;

				std::cout << "�������� ���������� (0, ����� ���������) : " << std::endl;

				for (const auto& ingredient : ingredients) {

					std::cout << ingredient.id << " | " << ingredient.name << " " << ingredient.type << " " << ingredient.count
						<< " " << ingredient.cost << std::endl;
				}

				while (isAdding) {

					std::cin >> choiceIngredient;

					if (choiceIngredient <= ingredients.size() && choiceIngredient > 0) {
						Ingredient ingredient = ingredients[choiceIngredient - 1];

						currIngredients.push_back(ingredient);
					}
					else if (choiceIngredient == 0) {
						isAdding = false;
					}
				}

				std::cout << "������� �������� ����� : ";
				std::cin >> descriptionDish;
				std::cout << "������� ����� ������� ����� : ";
				std::cin >> minutes;
				std::chrono::minutes preptime(minutes);

				std::cout << "������� ��������� ����� : ";
				std::cin >> costDish;

				Dish dish(dishes.size() + 1, nameDish, weightDish, currIngredients, descriptionDish, preptime, costDish);

				dishes.push_back(dish);


				std::string fileName = "dishes.txt";
				//������� ����
				std::ofstream file(fileName);

				//������� � ���� ��������
				for (const auto& data : dishes) {
					file << data.id << "-" << data.name << "-" << data.weight << "-";
					for (const auto& ingridient : currIngredients) {
						file << ingridient.id;
					}
					file << "-" << data.description << "-" << minutes << "-" << data.cost << "\n";
				}

				//��������� ����
				file.close();
			}

			break;
		case 6:

			isChangingDish = true;

			while (isChangingDish) {

				system("cls");

				std::cout << "�������� ���������� (��� 0, ����� �����) : " << std::endl;

				for (const auto& dish : dishes) {
					int minutesValue = dish.preptime.count();
					std::cout << dish.id << " | " << dish.name << " " << dish.weight << " �����, " << dish.description << " " 
						<< minutesValue << " �����, " << dish.cost << " ������." << std::endl;
				}

				int dishChoice;

				std::cin >> dishChoice;

				if (dishChoice <= dishes.size() && dishChoice > 0) {
					Dish dish = dishes[dishChoice - 1];

					//���� ��������
					std::cout << "������� �������� ����� : ";
					std::cin >> nameDish;
					std::cout << "������� ��� ����� : ";
					std::cin >> weightDish;
					std::cout << "������� ����������� ����� : ";

					int choiceIngredient;
					bool isAdding = true;

					std::vector<Ingredient> currIngredients;

					std::cout << "�������� ���������� (0, ����� ���������) : " << std::endl;

					for (const auto& ingredient : ingredients) {

						std::cout << ingredient.id << " | " << ingredient.name << " " << ingredient.type << " " << ingredient.count
							<< " " << ingredient.cost << std::endl;
					}

					while (isAdding) {

						std::cin >> choiceIngredient;

						if (choiceIngredient <= ingredients.size() && choiceIngredient > 0) {
							Ingredient ingredient = ingredients[choiceIngredient - 1];

							currIngredients.push_back(ingredient);
						}
						else if (choiceIngredient == 0) {
							isAdding = false;
						}
					}

					std::cout << "������� �������� ����� : ";
					std::cin >> descriptionDish;
					std::cout << "������� ����� ������� ����� : ";
					std::cin >> minutes;
					std::chrono::minutes preptime(minutes);

					std::cout << "������� ��������� ����� : ";
					std::cin >> costDish;

					//�������� ����� �� �������
					dishes.erase(std::remove_if(dishes.begin(), dishes.end(), [&](const Dish& u) { return u.id == dish.id; }), dishes.end());

					//��������� �������� dish
					dish.name = nameDish;
					dish.weight = weightDish;
					dish.ingridients = currIngredients;
					dish.description = descriptionDish;
					dish.preptime = preptime;
					dish.cost = costDish;

					dishes.push_back(dish);

					//���������� ������� �� �������� id
					std::sort(dishes.begin(), dishes.end(), [](const Dish& d1, const Dish& d2) {
						return d1.id < d2.id;
						});


					std::string fileName = "dishes.txt";

					//������� ����
					std::ofstream file(fileName);

					//������� � ���� ��������
					for (const auto& data : dishes) {
						file << data.id << "-" << data.name << "-" << data.weight << "-";
						for (const auto& ingridient : ingredients) {
							file << ingridient.id;
						}
						long long minutes = data.preptime.count();
						std::string timeString = std::to_string(minutes);
						file << "-" << data.description << "-" << minutes << "-" << data.cost << " \n";
					}

					//��������� ����
					file.close();
				}
				else if (dishChoice == 0) {
					isChangingDish = false;
				}
			}

			break;

		case 7:

			isDeletingDish = true;

			while (isDeletingDish) {
				system("cls");

				std::cout << "�������� ���������� (��� 0, ����� �����) : " << std::endl;

				for (const auto& dish : dishes) {
					int minutesValue = dish.preptime.count();
					std::cout << dish.id << " | " << dish.name << " " << dish.weight << " �����, " << dish.description << " " 
						<< minutesValue << " �����, " << dish.cost << " ������." << std::endl;
				}

				int dishChoice;

				std::cin >> dishChoice;

				if (dishChoice <= dishes.size() && dishChoice > 0) {
					Dish dish = dishes[dishChoice - 1];

					//�������� ����������� �� �������
					dishes.erase(std::remove_if(dishes.begin(), dishes.end(), [&](const Dish& u) { return u.id == dish.id; }), dishes.end());

					//���������� ������� �� �������� id
					std::sort(dishes.begin(), dishes.end(), [](const Dish& d1, const Dish& d2) {
						return d1.id < d2.id;
						});


					std::string fileName = "dishes.txt";

					//������� ����
					std::ofstream file(fileName);

					//������� � ���� ��������
					for (const auto& data : dishes) {
						file << data.id << "-" << data.name << "-" << data.weight << "-";
						for (const auto& ingridient : ingredients) {
							file << ingridient.id;
						}
						long long minutes = data.preptime.count();
						std::string timeString = std::to_string(minutes);
						file << "-" << data.description << "-" << minutes << "-" << data.cost << " \n";
					}

					//��������� ����
					file.close();
				}
				else if (dishChoice == 0) {
					isDeletingDish = false;
				}
			}

			break;

		case 8:

			std::cout << "���������� �������� �������������" << std::endl;

			for (const auto& activity : guestActivities) {
				std::cout << activity.id << " | " << activity.description << " " << activity.time << std::endl;
			}

			break;
		default:
			std::cout << "�������� ��������, ����" << std::endl;
			break;
		}

	}


};