#include <iostream>
#include <vector>

#include "arguments.h"
using std::cout;
using std::cin;
using std::endl;
using std::vector;


int main(int argc, char* argv[])
{
	vector<std::string> vec=arguments(argc, argv);
	//for(int i=0;i<vec.size();i++)
	//cout<<vec[i]<<"\n";
	return 0;
}