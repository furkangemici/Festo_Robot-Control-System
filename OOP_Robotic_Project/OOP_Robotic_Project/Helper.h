#pragma once

#include <iostream>
#include <vector>
using namespace std;
#include <sstream>

class Helper {
public:
    Helper() {}
	std::vector<double> convertToDoubles(const std::string& sensorValues) {
		std::vector<double> doubles;
		std::istringstream stream(sensorValues);
		std::string value;

		while (stream >> value) {
			try {
				doubles.push_back(std::stod(value));
			}
			catch (const std::invalid_argument& e) {
				std::cerr << "Geçersiz bir deðer bulundu: " << value << std::endl;
			}
		}
		return doubles;
	}
};