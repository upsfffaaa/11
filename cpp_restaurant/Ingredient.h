#ifndef INGREDIENT_H
#define INGREDIENT_H

#include <string>

// �����, �������� ���� ������������
class Ingredient {
public:
    int id;
    std::string name;
    std::string type;
    int count;
    float cost;

    // ����������� ������������
    Ingredient(const int& i, const std::string& n, const std::string& t, const int& c_, const float& c) : id(i), name(n), type(t), count(c_), cost(c){};
};

#endif
