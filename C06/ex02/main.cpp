#include "Decla.hpp"

#define BLUE		"\033[1;34m"
#define RESET		"\033[0m"

Base * generate(void)
{
    int r;
    srand(time(NULL));
    r = rand();
    if (r % 3 == 0)
        return (new A());
    else if (r % 3 == 1)
        return (new B());
    else
        return (new C());
}

void identify(Base* p)
{
    A *tryA = dynamic_cast<A *>(p);
    if (tryA == NULL)
    {
        B *tryB = dynamic_cast<B *>(p);
        if (tryB == NULL)
        {
            C *tryC = dynamic_cast<C *>(p);
            if (tryC == NULL)
                std::cout << "point: La base est de type inconnu" << std::endl;
            else
                std::cout << "point: La base est de type C" << std::endl;
        }
        else
            std::cout << "point: La base est de type B" << std::endl;
    }
    else
        std::cout << "point: La base est de type A" << std::endl;
}
void identify(Base &p)
{
    try
    {
        A &tryA = dynamic_cast<A &>(p);
        (void)tryA;
        std::cout << "ref: La base est de type A" << std::endl;
        return;
    }
    catch(...){}
    try
    {
        B &tryB = dynamic_cast<B &>(p);
        (void)tryB;
        std::cout << "ref: La base est de type B" << std::endl;
        return;
    }
    catch(...){}
    try
    {
        C &tryC = dynamic_cast<C &>(p);
        (void)tryC;
        std::cout << "ref: La base est de type C" << std::endl;
        return;
    }
    catch(...){}

    std::cout << "ref: La base est de type inconnu" << std::endl;
}

int main()
{
    Base *p = generate();
    std::cout << BLUE << "----------" << "Identify with pointers" << "----------" << RESET << std::endl;
    identify(p);
    std::cout << BLUE << "----------" << "Identify with reference" << "----------" << RESET << std::endl;
    identify(*p);
    return (0);
}