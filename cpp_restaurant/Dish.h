#ifndef DISH_H
#define DISH_H

#include <string>
#include <vector>
#include<chrono>

#include "Ingredient.h"

//Класс, хранящий поля блюд
class Dish {
public:
    int id;
    std::string name;
    float weight;
    std::vector<Ingredient> ingridients;
    std::string description;
    std::chrono::minutes preptime;
    float cost;

    //Конструктор блюд
    Dish(const int& i_, const std::string& n, const float& w, const std::vector<Ingredient>& i, const std::string& d, const std::chrono::minutes& p, const float& c) : 
        id (i_), name(n), weight(w), ingridients(i), description(d), preptime(p), cost(c) {}
};

#endif
