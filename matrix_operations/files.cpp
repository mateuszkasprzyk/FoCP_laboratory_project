#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "structures.h"

struct matrix load(std::string& file) {
	char hash;
	int rows=0,cols=0,value=0;

	std::vector<double> temp;

	std::ifstream input_file;
	std::stringstream line;
	std::string word;
	matrix main;

	input_file.open(file);

	if (input_file) {
		std::cout << "File " << file << " have been found and oppened succesfully\n";
		
		getline(input_file, word);
		if (word[0] == '#') {
			line << word;
			if (line >> hash >> rows >> hash >>cols ) {
				main.rows = rows;
				main.cols = cols;
			}
			temp.resize(cols);
			for (int i = 0; i < rows; i++) {
				getline(input_file, word);
				word += ";";
				line.clear();
				line << word;
				for (int j = 0; j < cols; j++) {
					if (line >> value >> hash) {
						temp[j] = value;
					}
					else {
						std::cout<<"There was an error while reading numbers in the matrix\n";
						main.values.resize(0);
						return main;
					}
				}
				main.values.push_back(temp);
			}
			std::cout << "Succesfully loaded matrix from file\n";
		}
		else {
			std::cout << "Cannot find the matrix size declaration on the begining of the file\n";
			main.values.resize(0);
			return main;
		}

		input_file.close();
	}
	else {
		std::cout << "Cannot find or open the matrix file\n";
	}
	return main;
}