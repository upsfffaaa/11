#ifndef GUESTACTIVITY_H
#define GUESTACTIVITY_H

#include <string>
#include <chrono>

class GuestActivity {
public:
	int id;
	std::string description;
	std::string time;

	// Конструктор
	GuestActivity(const int& i, const std::string& d, const std::string& t) : id(i), description(d), time(t) {};
};

#endif
