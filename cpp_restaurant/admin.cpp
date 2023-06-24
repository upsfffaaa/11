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

		std::cout << "Окно администратора." << "\n"
			<< "Выберите действие: " << "\n"
			<< "1 - Отредактировать пользователя;" << "\n"
			<< "2 - Добавить ингредиент;" << "\n"
			<< "3 - Изменить ингредиент;" << "\n"
			<< "4 - Удалить ингредиент;" << "\n"
			<< "5 - Добавить блюдо;" << "\n"
			<< "6 - Изменить блюдо;" << "\n"
			<< "7 - Удалить блюдо;" << "\n"
			<< "8 - Журнал активности гостя." << std::endl;

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

				std::cout << "Выберите пользователя (или 0, чтобы выйти) : " << std::endl;

				for (const auto& user : users) {

					std::cout << user.id << " | " << user.surname << " " << user.name << " " << user.patronymic
						<< " " << user.login
						<< " " << user.password << std::endl;
				}

				int userChoice;

				std::cin >> userChoice;

				if (userChoice <= users.size() && userChoice > 0) {
					User user = users[userChoice - 1];

					//ввод значений
					std::cout << "Введите фамилию : ";
					std::cin >> surname;
					std::cout << "Введите имя : ";
					std::cin >> name;
					std::cout << "Введите отчество : ";
					std::cin >> patronymic;
					std::cout << "Введите логин : ";
					std::cin >> login;
					std::cout << "Введите пароль : ";
					std::cin >> password;

					//удаление пользователя из вектора
					users.erase(std::remove_if(users.begin(), users.end(), [&](const User& u) { return u.id == user.id; }), users.end());

					//изменение значений user
					user.surname = surname;
					user.name = name;
					user.patronymic = patronymic;
					user.login = login;
					user.password = password;

					users.push_back(user);

					//сортировка вектора по значению id
					std::sort(users.begin(), users.end(), [](const User& u1, const User& u2) {
						return u1.id < u2.id;
						});


					std::string fileName = "users.txt";

					//создаем файл
					std::ofstream file(fileName);

					//заносим в него значения
					for (const auto& data : users) {
						file << data.id << "-" << data.surname << "-" << data.name << "-" << data.patronymic << "-" << data.login << "-" << data.password << "-" << data.role << "\n";
					}

					//закрываем файл
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

				std::cout << "Введите название ингредиента : ";
				std::cin >> nameIngredient;
				std::cout << "Введите тип ингредиента : ";
				std::cin >> typeIngredient;
				std::cout << "Введите количество ингредиента : ";
				std::cin >> countIngredient;
				std::cout << "Введите стоимость ингредиента : ";
				std::cin >> costIngredient;

				Ingredient ingredient(ingredients.size() + 1, nameIngredient, typeIngredient, countIngredient, costIngredient);

				ingredients.push_back(ingredient);


				std::string fileName = "ingredients.txt";
				//создаем файл
				std::ofstream file(fileName);

				//заносим в него значения
				for (const auto& data : ingredients) {
					file << data.id << "-" << data.name << "-" << data.type << "-" << data.count << "-" << data.cost << "\n";
				}

				//закрываем файл
				file.close();
			}

			break;
		case 3:

			isChangingIngredient = true;

			while (isChangingIngredient) {

				system("cls");

				std::cout << "Выберите ингредиент (или 0, чтобы выйти) : " << std::endl;

				for (const auto& ingredient : ingredients) {

					std::cout << ingredient.id << " | " << ingredient.name << " " << ingredient.type << " " << ingredient.count
						<< " " << ingredient.cost << std::endl;
				}

				int ingredientChoice;

				std::cin >> ingredientChoice;

				if (ingredientChoice <= ingredients.size() && ingredientChoice > 0) {
					Ingredient ingredient = ingredients[ingredientChoice - 1];

					//ввод значений
					std::cout << "Введите название : ";
					std::cin >> nameIngredient;
					std::cout << "Введите тип : ";
					std::cin >> typeIngredient;
					std::cout << "Введите количество : ";
					std::cin >> countIngredient;
					std::cout << "Введите цену : ";
					std::cin >> costIngredient;

					//удаление ингредиента из вектора
					ingredients.erase(std::remove_if(ingredients.begin(), ingredients.end(), [&](const Ingredient& u) { return u.id == ingredient.id; }), ingredients.end());

					//изменение значений ingredient
					ingredient.name = nameIngredient;
					ingredient.type = typeIngredient;
					ingredient.count = countIngredient;
					ingredient.cost = costIngredient;

					ingredients.push_back(ingredient);

					//сортировка вектора по значению id
					std::sort(ingredients.begin(), ingredients.end(), [](const Ingredient& i1, const Ingredient& i2) {
						return i1.id < i2.id;
						});


					std::string fileName = "ingredients.txt";

					//создаем файл
					std::ofstream file(fileName);

					//заносим в него значения
					for (const auto& data : ingredients) {
						file << data.id << "-" << data.name << "-" << data.type << "-" << data.count << "-" << data.cost << "\n";
					}

					//закрываем файл
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

				std::cout << "Выберите ингредиент (или 0, чтобы выйти) : " << std::endl;

				for (const auto& ingredient : ingredients) {

					std::cout << ingredient.id << " | " << ingredient.name << " " << ingredient.type << " " << ingredient.count
						<< " " << ingredient.cost << std::endl;
				}

				int ingredientChoice;

				std::cin >> ingredientChoice;

				if (ingredientChoice <= ingredients.size() && ingredientChoice > 0) {
					Ingredient ingredient = ingredients[ingredientChoice - 1];

					//удаление ингредиента из вектора
					ingredients.erase(std::remove_if(ingredients.begin(), ingredients.end(), [&](const Ingredient& u) { return u.id == ingredient.id; }), ingredients.end());

					//сортировка вектора по значению id
					std::sort(ingredients.begin(), ingredients.end(), [](const Ingredient& i1, const Ingredient& i2) {
						return i1.id < i2.id;
						});


					std::string fileName = "ingredients.txt";

					//создаем файл
					std::ofstream file(fileName);

					//заносим в него значения
					for (const auto& data : ingredients) {
						file << data.id << "-" << data.name << "-" << data.type << "-" << data.count << "-" << data.cost << "\n";
					}

					//закрываем файл
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

				std::cout << "Введите название блюда : ";
				std::cin >> nameDish;
				std::cout << "Введите вес блюда : ";
				std::cin >> weightDish;
				std::cout << "Введите ингредиенты блюда : ";

				int choiceIngredient;
				bool isAdding = true;

				std::vector<Ingredient> currIngredients;

				std::cout << "Выберите ингредиент (0, чтобы завершить) : " << std::endl;

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

				std::cout << "Введите описание блюда : ";
				std::cin >> descriptionDish;
				std::cout << "Введите время готовки блюда : ";
				std::cin >> minutes;
				std::chrono::minutes preptime(minutes);

				std::cout << "Введите стоимость блюда : ";
				std::cin >> costDish;

				Dish dish(dishes.size() + 1, nameDish, weightDish, currIngredients, descriptionDish, preptime, costDish);

				dishes.push_back(dish);


				std::string fileName = "dishes.txt";
				//создаем файл
				std::ofstream file(fileName);

				//заносим в него значения
				for (const auto& data : dishes) {
					file << data.id << "-" << data.name << "-" << data.weight << "-";
					for (const auto& ingridient : currIngredients) {
						file << ingridient.id;
					}
					file << "-" << data.description << "-" << minutes << "-" << data.cost << "\n";
				}

				//закрываем файл
				file.close();
			}

			break;
		case 6:

			isChangingDish = true;

			while (isChangingDish) {

				system("cls");

				std::cout << "Выберите ингредиент (или 0, чтобы выйти) : " << std::endl;

				for (const auto& dish : dishes) {
					int minutesValue = dish.preptime.count();
					std::cout << dish.id << " | " << dish.name << " " << dish.weight << " грамм, " << dish.description << " " 
						<< minutesValue << " минут, " << dish.cost << " рублей." << std::endl;
				}

				int dishChoice;

				std::cin >> dishChoice;

				if (dishChoice <= dishes.size() && dishChoice > 0) {
					Dish dish = dishes[dishChoice - 1];

					//ввод значений
					std::cout << "Введите название блюда : ";
					std::cin >> nameDish;
					std::cout << "Введите вес блюда : ";
					std::cin >> weightDish;
					std::cout << "Введите ингредиенты блюда : ";

					int choiceIngredient;
					bool isAdding = true;

					std::vector<Ingredient> currIngredients;

					std::cout << "Выберите ингредиент (0, чтобы завершить) : " << std::endl;

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

					std::cout << "Введите описание блюда : ";
					std::cin >> descriptionDish;
					std::cout << "Введите время готовки блюда : ";
					std::cin >> minutes;
					std::chrono::minutes preptime(minutes);

					std::cout << "Введите стоимость блюда : ";
					std::cin >> costDish;

					//удаление блюда из вектора
					dishes.erase(std::remove_if(dishes.begin(), dishes.end(), [&](const Dish& u) { return u.id == dish.id; }), dishes.end());

					//изменение значений dish
					dish.name = nameDish;
					dish.weight = weightDish;
					dish.ingridients = currIngredients;
					dish.description = descriptionDish;
					dish.preptime = preptime;
					dish.cost = costDish;

					dishes.push_back(dish);

					//сортировка вектора по значению id
					std::sort(dishes.begin(), dishes.end(), [](const Dish& d1, const Dish& d2) {
						return d1.id < d2.id;
						});


					std::string fileName = "dishes.txt";

					//создаем файл
					std::ofstream file(fileName);

					//заносим в него значения
					for (const auto& data : dishes) {
						file << data.id << "-" << data.name << "-" << data.weight << "-";
						for (const auto& ingridient : ingredients) {
							file << ingridient.id;
						}
						long long minutes = data.preptime.count();
						std::string timeString = std::to_string(minutes);
						file << "-" << data.description << "-" << minutes << "-" << data.cost << " \n";
					}

					//закрываем файл
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

				std::cout << "Выберите ингредиент (или 0, чтобы выйти) : " << std::endl;

				for (const auto& dish : dishes) {
					int minutesValue = dish.preptime.count();
					std::cout << dish.id << " | " << dish.name << " " << dish.weight << " грамм, " << dish.description << " " 
						<< minutesValue << " минут, " << dish.cost << " рублей." << std::endl;
				}

				int dishChoice;

				std::cin >> dishChoice;

				if (dishChoice <= dishes.size() && dishChoice > 0) {
					Dish dish = dishes[dishChoice - 1];

					//удаление ингредиента из вектора
					dishes.erase(std::remove_if(dishes.begin(), dishes.end(), [&](const Dish& u) { return u.id == dish.id; }), dishes.end());

					//сортировка вектора по значению id
					std::sort(dishes.begin(), dishes.end(), [](const Dish& d1, const Dish& d2) {
						return d1.id < d2.id;
						});


					std::string fileName = "dishes.txt";

					//создаем файл
					std::ofstream file(fileName);

					//заносим в него значения
					for (const auto& data : dishes) {
						file << data.id << "-" << data.name << "-" << data.weight << "-";
						for (const auto& ingridient : ingredients) {
							file << ingridient.id;
						}
						long long minutes = data.preptime.count();
						std::string timeString = std::to_string(minutes);
						file << "-" << data.description << "-" << minutes << "-" << data.cost << " \n";
					}

					//закрываем файл
					file.close();
				}
				else if (dishChoice == 0) {
					isDeletingDish = false;
				}
			}

			break;

		case 8:

			std::cout << "Активность гостевых пользователей" << std::endl;

			for (const auto& activity : guestActivities) {
				std::cout << activity.id << " | " << activity.description << " " << activity.time << std::endl;
			}

			break;
		default:
			std::cout << "Неверное действие, ПОКА" << std::endl;
			break;
		}

	}


};