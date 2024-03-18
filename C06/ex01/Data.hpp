#ifndef Data_HPP
#define Data_HPP

class Data
{
    public :
        Data(void);
        Data(const Data &cop);
        Data &operator=(const Data &eg);
        virtual ~Data(void);
        int _itest;
        char _ctest;
    private :


};

#endif