#include <iostream>
#include <vector>

#include "arguments.h"


int main(int argc, char* argv[])
{
	if (!show_help(argc, argv)) {
		if (!missing_arg(argc)) {
			std::vector<std::string> vec = arguments(argc, argv);
			printing_arguments(vec);
			if (arg_errors(argc, argv)) {
				
			}
		}
		
	}

	return 0;
}