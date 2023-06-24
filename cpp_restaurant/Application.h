#ifndef APPLICATION_H
#define APPLICATION_H

#include <string>
#include <vector>

#include "Ingredient.h"

class Ingredient;

// ласс, хран€щий пол€ заказа ингридиентов
class Application {
public:
    int id;
    std::vector<Ingredient> ingredients;        //тип и количество ингридиентов возьмем напр€мую отсюда
    std::string status;
    float sum;

    // онструктор заказа ингридиентов
    Application(const int& i, const std::vector<Ingredient>& i_, const std::string& s_, const float& s) : id(i), ingredients(i_), status(s_), sum(s) {}
};

#endif