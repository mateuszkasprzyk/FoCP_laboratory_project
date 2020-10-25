#include <iostream>
#include <vector>

#include "arguments.h"
#include "files.h"
#include "operations.h"

int main(int argc, char* argv[])
{
	if (!show_help(argc, argv)) {
		if (!missing_arg(argc)) {
			std::vector<std::string> vec = arguments(argc, argv);
			printing_arguments(vec);
			std::cout << "-----------------------------------------------------------\n";
			if (arg_errors(argc, argv)) {
				std::cout << "-----------------------------------------------------------\n";
				std::vector<std::vector<std::vector<int>>> matrix;
				for (int j = 0; j < 2; j++) {
					if (vec[j] != "") {
							matrix.push_back(load(vec[j]));
						
						if (matrix[j].size() != 0) {
							std::cout << "-----------------------------------------------------------\nMatrix " << char(j + 65) << ":\n";
							show(matrix[j]);
							std::cout << "-----------------------------------------------------------\n";
						}
					}
					else {
						matrix.push_back(std::vector<std::vector<int>>{});
					}
				}
				for (int j = 0; j < 2; j++) {
					if (matrix[j].size() > 1) {
						int size = 1,temp=1;
						std::cout << "Determinant of Matrix " << char(j + 65) << ": " << determinant( matrix[j]) << std::endl;
					}
				}
			}
		}
	}
	return 0;
}