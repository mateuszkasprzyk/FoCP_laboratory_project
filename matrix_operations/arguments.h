#ifndef ARGUMENTS_H
#define ARGUMENTS_H

std::vector<std::string> arguments(int& number, char** arg);
int arg_errors(int& number, char** arg);
int show_help(int& number, char** arg);
void printing_arguments(std::vector<std::string>& temp);
int missing_arg(int& number);


#endif
