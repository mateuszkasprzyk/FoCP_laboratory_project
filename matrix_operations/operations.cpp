#include <iostream>
#include <vector>
#include <iomanip>

void show(std::vector<std::vector<int>>& tab) {
	std::cout << "Size(" << tab[0][0] << " rows, " << tab[0][1] << " columns)\n";
	for (int i = 1; i < tab[0][0]+1; i++) {
		for (int j = 0; j < tab[0][1]; j++) {
			std::cout <<std::setw(10)<< tab[i][j] << " ";
		}
		std::cout << std::endl;
	}
}