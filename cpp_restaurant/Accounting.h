#ifndef ACCOUNTING_H
#define ACCOUNTING_H

#include <string>
#include <vector>

#include "Order.h"

//Класс, хранящий поля заказа ингридиентов
class Accounting {
public:
    float balance;                      //баланс ресторана
    std::vector<Order> orders;          //все заказы блюд
    float globalSum;                    //общая сумма всех заказов
    float totalPurchase;                //общая сумма закупки ингредиентов

    //Конструктор заказа ингридиентов
    Accounting(const float& b, const std::vector<Order>& o, const float& g, const float& t) : balance(b), orders(o), globalSum(g), totalPurchase(t) {}
};

#endif