#ifndef USER_H
#define USER_H

#include <string>

//Класс, хранящий поля пользователя
class User {
public:
    int id;
    std::string surname;
    std::string name;
    std::string patronymic;
    std::string login;
    std::string password;
    std::string role;

    //Конструктор пользователя
    User(const int& i, const std::string& s, const std::string& n, const std::string& p, const std::string& l, const std::string& p_, const std::string& r) : 
        id(i), surname(s), name(n), patronymic(p), login(l), password(p_), role(r) {}
};

#endif