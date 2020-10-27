#ifndef STRUCTURES_H
#define STRUCTURES_H
#include <vector>

struct matrix {
	int rows;
	int cols;
	std::vector<std::vector<double>> values;
};

#endif