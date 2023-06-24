#ifndef FILELOGIC_H
#define FILELOGIC_H

#include<string>
#include <fstream>
#include <sstream>

class FileLogic {
public:
	bool isFileExists(const std::string& filename) {
		std::ifstream file(filename);
		return file.good();
	}

	bool isFileEmpty(const std::string& filename) {
		std::ifstream file(filename);
		return file.peek() == std::ifstream::traits_type::eof();
	}
};

#endif