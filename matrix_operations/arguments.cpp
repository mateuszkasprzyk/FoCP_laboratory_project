#include <vector>
#include <iostream>
#include <string>
#include <iomanip>
int is_help(int& number, char** arg) {
	for (int i = 1; i < number; i++) {
		if (std::string(arg[i]) == "-h")
			return 1;
	}
	return 0;
}

int arg_errors(int& number, char** arg) {
	std::vector<double> tab{0,0,0,0};
	if ((number - 1) % 2 == 0) {	//checking if there isn't any switch without argument
		tab.resize(4);

		for (int i = 0; i < number; i++) { //counting how many times every switch occured
			std::string argument = std::string(arg[i]);
			if (argument == "-a") {
				tab[0]++;
			}
			if (argument == "-b") {
				tab[1]++;
			}
			if (argument == "-o") {
				tab[2]++;
			}
			if (argument == "-operation") {
				tab[3]++;
			}

		}
		if (tab[0] > 1 || tab[1] > 1 || tab[2]>1 || tab[3] > 1) {
			std::cout << "You have used one switch multiple times. The secound value was accepted\n";
		}
		else {
			if ((tab[0] + tab[1]+tab[2]+tab[3]) / 4 <= 0.5) {
				std::cout << "You must pass operation name, outpute file and at least one matrix source file!!!\n";
			}
			else {
				std::cout << "All necesary arguments were found\n";
				
			}
		}
	}
	else {
		std::cout << "There is an switch without argument\nPlease provide argument for every switch you use!\n";
		return 0;
	}

	return 1;

}

std::vector<std::string> arguments(int& number, char** arg) {
	std::vector<std::string> temp={"","","",""};	//creating and initializing vector of strings

	if (!is_help(number, arg)) {
		if (arg_errors(number, arg)) { //checking if there is argument for every switch
			for (int i = 0; i < number; i++) {				//loop for interating through table of arguments
				std::string argument = std::string(arg[i]); //assigning current argument form arg table to string variable 'argument'
				if (argument == "-a") {
					temp[0] = std::string(arg[i + 1]);
				}
				if (argument == "-b") {
					temp[1] = std::string(arg[i + 1]);
				}
				if (argument == "-o") {
					temp[2] = std::string(arg[i + 1]);
				}
				if (argument == "-operation") {
					temp[3] = std::string(arg[i + 1]);
				}

			}
		}
		
		std::cout << "\nProgram recognized following arguments:\n" << std::endl << std::setw(31) << std::left
			<< "Input file for matrix A: "<< temp[0] << std::endl << std::setw(31) << std::left
			<< "Input file for matrix B: " << temp[1] << std::endl << std::setw(31)<<std::left
			<< "File for results: " << temp[2] << std::endl << std::setw(31) << std::left
			<< "Name of operation to perform: " << temp[3] << std::endl;
	}
	else {
			std::cout << "This program can use following switches:" << std::endl
				<< "-a 'firstmatrixfile'.txt --> input file for A matrix" << std::endl
				<< "-b 'secondmatrixfile'.txt --> input file for B matrix" << std::endl
				<< "-o 'outputfile'.txt --> output file with resutls of calcuation or error message if calcualtions cannot be performed" << std::endl
				<< "-operation 'name' --> name of operation to be performed, example \"-operation add\"" << std::endl
				<< "available operation names: add, subtract, multiply, transform, invers, determinant " << std::endl;
		}
	
	return temp;
}