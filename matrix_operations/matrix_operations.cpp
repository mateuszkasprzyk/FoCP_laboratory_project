#include <iostream>
#include <vector>

#include "arguments.h"
#include "files.h"
#include "operations.h"
#include "structures.h"


int main(int argc, char* argv[])
{
	if (!show_help(argc, argv)) {
		if (!missing_arg(argc)) {
			std::vector<std::string> vec = arguments(argc, argv);
			printing_arguments(vec);
			std::cout << "-----------------------------------------------------------\n";
			if (arg_errors(argc, argv)) {
				std::cout << "-----------------------------------------------------------\n";
				std::vector<matrix> matrixes;
				for (int j = 0; j < 2; j++) {
					if (vec[j] != "") {
						matrixes.push_back(load(vec[j]));
						std::cout << "-----------------------------------------------------------\n";
						if (matrixes[j].values.size() != 0) {
							std::cout << "Matrix " << char(j + 65) << ":\n";
							show(matrixes[j]);
							std::cout << "-----------------------------------------------------------\n";
						}
					}
					else {
						matrix temp;
						temp.values.resize(0);
						matrixes.push_back(temp);
					}
				}
				for (int j = 0; j < 2; j++) {
					if (matrixes[j].values.size() > 1) {
						std::cout << "Determinant of Matrix " << char(j + 65) << ": " << determinant( matrixes[j]) << std::endl;
					}
				}
			}
		}
	}
	return 0;
}