#include <vector>
#include <iostream>
#include <string>

std::vector<std::string> arguments(int& number, char** arg) {
	std::vector<std::string> temp={"","","",""};

	for (int i = 0; i < number; i++) {
		std::string argument = std::string(arg[i]);
		if (argument == "-h") {
			std::cout << "This program can use following switches:" << std::endl
				<< "-a 'firstmatrixfile'.txt --> input file for A matrix" << std::endl
				<< "-b 'secondmatrixfile'.txt --> input file for B matrix" << std::endl
				<< "-o 'outputfile'.txt --> output file with resutls of calcuation or error message if calcualtions cannot be performed" << std::endl
				<< "-operation 'name' --> name of operation to be performed, example \"-operation add\"" << std::endl
				<< "available operation names: add, subtract, multiply, transform, invers, determinant " << std::endl;
			temp.resize(0);
			return temp;
		}
		if (argument == "-a") {
			if (temp[0] == "") {
				temp[0] = std::string(arg[i + 1]);
			}
			else {
				std::cout << "You used " << argument << " switch twice, second value will not be taken into account\n";
			}
		}
		if (argument == "-b") {
			if (temp[1] == "") {
				temp[1] = std::string(arg[i + 1]);
			}
			else {
				std::cout << "You used " << argument << " switch twice, second value will not be taken into account\n";
			}
		}
		if (argument == "-o") {
			if (temp[2] == "") {
				temp[2] = std::string(arg[i + 1]);
			}
			else {
				std::cout << "You used "<<argument<<" switch twice, second value will not be taken into account\n";
			}
		}
		if (argument == "-operation") {
			if (temp[3] == "") {
				temp[3] = std::string(arg[i + 1]);
			}
			else {
				std::cout << "You used " << argument << " switch twice, second value will not be taken into account\n";
			}
		}

	}
	if ((temp[0] || temp[1])== "") {
		std::cout << "At least one switch value is missing\n";
	}
	return temp;
}