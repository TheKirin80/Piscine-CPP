#include "Data.hpp"

Data::Data(void) : _itest(0) , _ctest('a')
{
    return;
}
Data::Data(const Data &cop)
{
    *this = cop;
}
Data &Data::operator=(const Data &eg)
{
    if (this != &eg)
    {

    }
    return (*this);
}
Data::~Data(void)
{
    return;
}

