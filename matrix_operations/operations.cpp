#include <iostream>
#include <vector>
#include <iomanip>

#include "operations.h"

long long int determinant( std::vector<std::vector<int>>& tab) {
	if (tab[0][0] == tab[0][1]) {
		int last = 1;
		int counter = tab[0][0];

		std::vector<std::vector<long long int>> temp(counter+1,std::vector<long long int>(counter));
		temp[0][0] = tab[0][0];
		temp[0][1] = tab[0][1];
		for (int i = 1; i < tab.size(); i++) {
			for(int j=0;j< tab[1].size();j++)
				temp[i][j]=tab[i][j];
		}

		std::vector<std::vector<long long int>> temp1 = temp;

		for (int i = 0; i < counter; i++) {
			
			for (int j = 0; j < counter; j++) {
				for (int k = 0; k < counter; k++) {
					if (j!=i) {
						temp[j+1][k]=((temp1[i+1][i] * temp1[j + 1][k]) - (temp1[j + 1][i] * temp1[i+1][k])) / last;
						if (temp[j+1][k]<std::numeric_limits<long long int>::max() && temp[j + 1][k]>std::numeric_limits<long long int>::min()) {
						}
						else {
							std::cout<<"Integer overflow detected! No results \n";
							return 0;
						}
						//std::cout << temp1[i + 1][i] << " * " << temp1[j + 1][k] << " - " << temp1[j + 1][i] << " * " << temp1[i + 1][k] << " / " << last<<std::endl;

					}
					else {
						temp[j + 1][k] = temp1[j + 1][k];
					}
					//show(temp);
				}
				//std::cout << std::endl;
			}
			temp1 = temp;
			last = temp1[i + 1][i];
		}
		return temp1[counter][counter-1];
	}
	else {
		std::cout << "You matrix must have the same number of rows and columns\n";
	}
	return 0;
}

void show(std::vector<std::vector<int>>& tab) {
	std::cout << "Size(" << tab[0][0] << " rows, " << tab[0][1] << " columns)\n";
	for (int i = 1; i < tab[0][0]+1; i++) {
		for (int j = 0; j < tab[0][1]; j++) {
			std::cout <<std::setw(11)<< tab[i][j] << " ";
		}
		std::cout << std::endl;
	}
}