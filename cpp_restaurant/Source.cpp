#include<iostream>
#include<stdio.h>
#include <vector>
#include<string>
#include <fstream>
#include <sstream>
#include <chrono>


#include "aut.cpp"

int main() {

	// Установка русской локали
	std::setlocale(LC_ALL, "Russian");


	aut authorization;

	authorization.Auth();

	return 0;
}