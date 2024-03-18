#include "Serializer.hpp"
#include "Data.hpp"

#include <cstdlib>

#define BLUE		"\033[1;34m"
#define RESET		"\033[0m"

int main(void) {

	Data*		data;
	uintptr_t	ptr = 0;
	Data*		oth = NULL;

	data = new Data();

	std::cout << "data:\t\t" << data <<std::endl;
	std::cout << "data->_itest:\t" << data->_itest <<std::endl;
    std::cout << "data->_ctest:\t" << data->_ctest <<std::endl;
	std::cout << "oth :\t" << oth <<std::endl;

	std::cout << BLUE << "Serialize data" << RESET << std::endl;

	ptr = Serializer::serialize(data);
	std::cout << "ptr :\t" << ptr <<std::endl;

	std::cout << BLUE << "Deserialize oth" << RESET << std::endl;

	oth = Serializer::deserialize(ptr);
	std::cout << "oth :\t" << oth <<std::endl;
	std::cout << "oth->_itest :\t" << data->_itest <<std::endl;
    std::cout << "oth->_ctest :\t" << data->_ctest <<std::endl;

	std::cout << BLUE << "Serialize data" << RESET << std::endl;

	ptr = Serializer::serialize(oth);
	std::cout << "ptr :\t" << ptr <<std::endl;
	
	delete data;

}