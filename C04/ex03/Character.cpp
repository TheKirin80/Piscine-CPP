#include "Character.hpp"

Character::Character(void) : _type("noname")
{
    for (int i = 0; i < 4 ; i++){
        this->bag[i] = NULL;
    }
    std::cout << "Character Default Constructor" << std::endl;
    return;
}

Character::Character(std::string const & name) : _name(name)
{
    for (int i = 0; i < 4 ; i++){
        this->bag[i] = NULL;
    }
    std::cout << "Character NameSet Constructor" << std::endl;
    return;
}

Character::Character(const Character &cop)
{
    for (int i = 0; i < 4 ; i++){ 
        if (this->bag[i] != NULL){ // Remet le sac a NULL
            delete this->bag[i];
            this->bag[i] = NULL;
        }
        if (cop.bag[i] != NULL) // Rempli le sac si le sac modele n'est pas vide

            this->bag[i] = cop.bag[i]->clone();
    }
    this->_name = cop._name;
    std::cout << "Character Recopy Constructor" << std::endl;
}
Character &Character::operator=(const Character &eg)
{
    std::cout << "Copy assignment operator Character called" << std::endl;
    _name = eg._name;
    for (int i = 0; i < 4 ; i++){
        if (this->bag[i] != NULL){
            delete this->bag[i];
            this->bag[i] = NULL;
        }
        if (eg.bag[i] != NULL){ // Rempli le sac si le sac modele n'est pas vide
            this->bag[i] = eg.bag[i]->clone();
        }
    }
    return (*this);
}
Character::~Character(void)
{
    std::cout << "Character Default Destructor" << std::endl;
    return;
}