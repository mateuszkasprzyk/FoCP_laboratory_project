#include <iostream>
#include <vector>
#include <iomanip>

#include "operations.h"
#include "structures.h"

long long int determinant(matrix& temps) {
	if (temps.rows == temps.cols) {
		int last = 1;
		int counter = temps.rows;

		std::vector<std::vector<long long int>> temp(counter,std::vector<long long int>(counter));
		for (int i = 0; i < temps.values.size(); i++) {
			for(int j=0;j< temps.values[1].size();j++)
				temp[i][j]=temps.values[i][j];
		}

		std::vector<std::vector<long long int>> temp1 = temp;

		for (int i = 0; i < counter; i++) {
			
			for (int j = 0; j < counter; j++) {
				for (int k = 0; k < counter; k++) {
					if (j!=i) {
						temp[j][k]=((temp1[i][i] * temp1[j][k]) - (temp1[j][i] * temp1[i][k])) / last;
						if (temp[j][k]<std::numeric_limits<long long int>::max() && temp[j][k]>std::numeric_limits<long long int>::min()) {
						}
						else {
							std::cout<<"Integer overflow detected! No results \n";
							return 0;
						}
						//std::cout << temp1[i][i] << " * " << temp1[j][k] << " - " << temp1[j][i] << " * " << temp1[i][k] << " / " << last<<std::endl;

					}
					else {
						temp[j][k] = temp1[j][k];
					}
				}
				//std::cout << std::endl;
			}
			temp1 = temp;
			last = temp1[i][i];
		}
		return temp1[counter-1][counter-1];
	}
	else {
		std::cout << "You matrix must have the same number of rows and columns\n";
	}
	return 0;
}

void show(matrix &temp) {
	std::cout << "Size(" << temp.rows << " rows, " << temp.cols << " columns)\n";
	for (int i = 0; i < temp.rows; i++) {
		for (int j = 0; j < temp.cols; j++) {
			std::cout <<std::setw(11)<<std::setprecision(15)<< temp.values[i][j] << " ";
		}
		std::cout << std::endl;
	}
}