#include <iostream>
#include <vector>

#include "arguments.h"
#include "files.h"
#include "operations.h"

int test;
int main(int argc, char* argv[])
{
	if (!show_help(argc, argv)) {
		if (!missing_arg(argc)) {
			std::vector<std::string> vec = arguments(argc, argv);
			printing_arguments(vec);
			std::cout << "-----------------------------------------------------------\n";
			if (arg_errors(argc, argv)) {
				std::cout << "-----------------------------------------------------------\n";
					if (vec[0] != "") {		
						std::vector<std::vector<int>> matrix_a = load(vec[0]);
						std::cout << "-----------------------------------------------------------\nMatrix A:\n";
						show(matrix_a);
					}
					std::cout << "-----------------------------------------------------------\n";
					if (vec[1] != "") {
						
						std::vector<std::vector<int>> matrix_b = load(vec[1]);
						std::cout << "-----------------------------------------------------------\nMatrix B:\n";
						show(matrix_b);
					}

			}
		}
		
	}
	return 0;
}