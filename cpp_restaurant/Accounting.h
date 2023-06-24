#ifndef ACCOUNTING_H
#define ACCOUNTING_H

#include <string>
#include <vector>

#include "Order.h"

//�����, �������� ���� ������ ������������
class Accounting {
public:
    float balance;                      //������ ���������
    std::vector<Order> orders;          //��� ������ ����
    float globalSum;                    //����� ����� ���� �������
    float totalPurchase;                //����� ����� ������� ������������

    //����������� ������ ������������
    Accounting(const float& b, const std::vector<Order>& o, const float& g, const float& t) : balance(b), orders(o), globalSum(g), totalPurchase(t) {}
};

#endif