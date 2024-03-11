#include "ICharacter.hpp"
#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include <iostream>
#include <cstdlib>

// int main()
// {
//     IMateriaSource* src = new MateriaSource();
//     src->learnMateria(new Ice());
//     src->learnMateria(new Cure());
//     ICharacter* me = new Character("me");
//     AMateria* tmp1,* tmp2;
//     tmp1 = src->createMateria("ice");
//     me->equip(tmp1);
//     tmp2 = src->createMateria("cure");
//     me->equip(tmp2);
//     ICharacter* bob = new Character("bob");
//     me->use(0, *bob);
//     me->use(1, *bob);
//     ICharacter* bobby = new Character("bobby");
//     {
//         ICharacter *bobbytmp = bobby;
//         (void)bobbytmp;
//     }

//     delete tmp1;
//     delete tmp2;
//     delete bob;
//     delete me;
//     delete src;
//     delete bobby;
//     return 0;
// }

int main(void)
{
	{
		IMateriaSource	*src = new MateriaSource();

		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
        AMateria *tmp1, *tmp2;
        tmp1 = src->createMateria("ice");
        tmp2 = src->createMateria("cure");
		{
			ICharacter* me = new Character("me");

			{
				me->equip(tmp1);
				me->equip(tmp2);
				me->equip(tmp1);
				me->equip(tmp2);
				me->equip(tmp1);
			}
			{
				me->unequip(2);
				me->unequip(3);
				me->unequip(-1);
				me->unequip(42);
			}
			{
				ICharacter* bob = new Character("bob");

				me->use(0, *bob);
				me->use(1, *bob);
				delete bob;
			}
			delete me;
		}
		{
			Character	ali = Character("ali");
			Character	sterd;

			{
				ali.equip(tmp1);
				ali.equip(tmp2);
				ali.equip(tmp2);
				ali.equip(tmp2);
				sterd.equip(tmp2);
			}
			{
				ali.unequip(2);
				ali.unequip(3);
			}
			{
				ali.use(0, sterd);
				ali.use(1, sterd);
				ali.use(2, sterd);
				sterd = ali;
				ali.use(0, sterd);
				ali.use(1, sterd);
			}
		}
		delete src;
        delete tmp1;
        delete tmp2;
	}
	{
		MateriaSource	*src1 = new MateriaSource();
        {
		    MateriaSource *src2 = src1;
            (void)src2;
        }
		delete src1;
	}
    {
        ICharacter* me = new Character("me");
        {
            ICharacter* bobby = me;
            (void)bobby;
        }
        delete me;
    }
	return (0);
}