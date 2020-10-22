#include <vector>
#include <iostream>
#include <string>

std::vector<std::string> arguments(int& number, char** arg) {
	std::vector<std::string> temp={"","","",""};	//creating and initializing vector of strings with 0 characters in each cell

	for (int i = 0; i < number; i++) {				//loop for interating through table of arguments
		std::string argument = std::string(arg[i]); //assigning current argument form arg table to string variable 'argument'
		if (argument == "-h") {		//if -h display help
			std::cout << "This program can use following switches:" << std::endl
				<< "-a 'firstmatrixfile'.txt --> input file for A matrix" << std::endl
				<< "-b 'secondmatrixfile'.txt --> input file for B matrix" << std::endl
				<< "-o 'outputfile'.txt --> output file with resutls of calcuation or error message if calcualtions cannot be performed" << std::endl
				<< "-operation 'name' --> name of operation to be performed, example \"-operation add\"" << std::endl
				<< "available operation names: add, subtract, multiply, transform, invers, determinant " << std::endl;
			temp.resize(0); //i will leave it for now but I think there is better one of doing this
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
	for (int i = 0; i < temp.size(); i++)
		if (temp[i] == "") {
			std::cout << "Missing argument ";
			switch (i) {
			case 0:std::cout << "-a\n";
				break;
			case 1:std::cout << "-b\n";
				break;
			case 2:std::cout << "-o\n";
				break;
			case 3:std::cout << "-operation\n";
				break;
			}
		}
	return temp;
}