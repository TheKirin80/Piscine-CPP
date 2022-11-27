#ifndef HEADER_HPP
#define HEADER_HPP

#define FOUND	0
#define OK		0
#define ERROR	1
#define N_FOUND	1

#include <iostream>
#include <string>
#include <cctype>
#include <unistd.h>
#include "Contact.hpp"
#include "PhoneBook.hpp"

int wspace(std::string *str);
int	isnum(std::string *str);
int secure_getline(std::string *str);
int instancy(std::string post, std::string *str, int i);
std::string affichage(std::string str);
#endif

