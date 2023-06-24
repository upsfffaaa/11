#ifndef APPLICATION_H
#define APPLICATION_H

#include <string>
#include <vector>

#include "Ingredient.h"

class Ingredient;

//�����, �������� ���� ������ ������������
class Application {
public:
    int id;
    std::vector<Ingredient> ingredients;        //��� � ���������� ������������ ������� �������� ������
    std::string status;
    float sum;

    //����������� ������ ������������
    Application(const int& i, const std::vector<Ingredient>& i_, const std::string& s_, const float& s) : id(i), ingredients(i_), status(s_), sum(s) {}
};

#endif