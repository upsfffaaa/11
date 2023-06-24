#ifndef ORDER_H
#define ORDER_H

#include <string>
#include <vector>

#include "Dish.h"

//Класс, хранящий поля заказа
class Order {
public:
    int id;
    std::vector<Dish> dishes;
    std::string status;
    float sum;

    //Конструктор заказа
    Order(const int& i, const std::vector<Dish>& d, const std::string& s, const float& s_) : id(i), dishes(d), status(s), sum(s_) {}
};

#endif