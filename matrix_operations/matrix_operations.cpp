#include <iostream>
#include <vector>

#include "arguments.h"


int main(int argc, char* argv[])
{
	std::vector<std::string> vec=arguments(argc, argv);
	return 0;
}