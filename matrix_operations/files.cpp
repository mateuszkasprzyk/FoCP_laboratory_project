#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

std::vector<std::vector<int>> load(std::string& file) {
	char hash;
	int value;

	std::vector<int> temp;
	std::vector<std::vector<int>> main;

	std::ifstream input_file;
	std::stringstream line;
	std::string word;

	input_file.open(file);

	if (input_file) {
		std::cout << "File " << file << " have been found and oppened succesfully\n";

		getline(input_file, word);
		if (word[0] == '#') {
			line << word;
			while (line >> hash >> value) {
				temp.push_back(value);
			}
			main.push_back(temp);
			temp.resize(main[0][1]);
			for (int i = 0; i < main[0][0]; i++) {
				getline(input_file, word);
				word += ";";
				line.clear();
				line << word;
				for (int j = 0; j < main[0][1]; j++) {
					if (line >> value >> hash) {
						temp[j] = value;
					}
					else {
						std::cout<<"There was an error while reading numbers in the matrix\n";
						main.resize(0);
						return main;
					}
				}
				main.push_back(temp);
			}
			std::cout << "Succesfully loaded matrix from file\n";
		}
		else {
			std::cout << "Cannot find the matrix size declaration on the begining of the file\n";
			main.resize(0);
			return main;
		}

		input_file.close();
	}
	else {
		std::cout << "Cannot find or open the matrix file\n";
	}
	return main;
}