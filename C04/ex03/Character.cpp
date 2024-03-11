#include "Character.hpp"

Character::Character(void) : _name("noname")
{
    for (int i = 0; i < 4 ; i++){
        this->_bag[i] = NULL;
    }
    this->_floor = NULL;
    std::cout << "Character Default Constructor" << std::endl;
    return;
}

Character::Character(std::string const & name) : _name(name)
{
    for (int i = 0; i < 4 ; i++){
        this->_bag[i] = NULL;
    }
    this->_floor = NULL;
    std::cout << "Character NameSet Constructor" << std::endl;
    return;
}

Character::Character(const Character &cop)
{
    for (int i = 0; i < 4 ; i++){ 
        if (this->_bag[i] != NULL){ // Remet le sac a NULL
            delete this->_bag[i];
            this->_bag[i] = NULL;
        }
        if (cop._bag[i] != NULL) // Rempli le sac si le sac modele n'est pas vide
            this->_bag[i] = cop._bag[i]->clone();
    }
    if (this->_floor != NULL){
        delete this->_floor;
        this->_floor = cop._floor->clone();
    }
    this->_name = cop._name;
    std::cout << "Character Recopy Constructor" << std::endl;
}
Character &Character::operator=(const Character &eg)
{
    _name = eg._name;
    for (int i = 0; i < 4 ; i++){
        if (this->_bag[i] != NULL){
            delete this->_bag[i];
            this->_bag[i] = NULL;
        }
        if (eg._bag[i] != NULL){ // Rempli le sac si le sac modele n'est pas vide
            this->_bag[i] = eg._bag[i]->clone();
        }
    }
    if (this->_floor != NULL){
        delete this->_floor;
        this->_floor = eg._floor->clone();
    }
    std::cout << "Copy assignment operator Character called" << std::endl;
    return (*this);
}
Character::~Character(void)
{
    std::cout << "Character Default Destructor" << std::endl;
    for (int i = 0; i < 4 ; i++){
        if (this->_bag[i] != NULL){
            delete this->_bag[i];
            this->_bag[i] = NULL;
        }
    }
    if (this->_floor != NULL){
        delete this->_floor;
        this->_floor = NULL;
    }
    return;
}
std::string const & Character::getName(void) const{
    return (this->_name);
}
void Character::add_floor(AMateria *m)
{
    if (this->_floor == NULL)
        this->_floor = m;
    else{
        delete this->_floor;
        this->_floor = m;
    }
    std::cout << "Materia is on the floor" << std::endl;
}
void Character::equip(AMateria* m)
{
    for (int i = 0; i < 4; i++){
        if (this->_bag[i] == NULL){
            this->_bag[i] = m->clone();
            std::cout << "Your Materia is added" << std::endl;
            return;
        }
    }
    std::cout << "Sorry mate but your bag is full" << std::endl;
}
void Character::unequip(int idx)
{
    if (idx >= 0 && idx < 4){
        if (this->_bag[idx] != NULL){
            this->add_floor(this->_bag[idx]);
            this->_bag[idx] = NULL;
            std::cout << "Success Unequip Materia" << std::endl;
        }
    }
}
void Character::use(int idx, ICharacter& target){
    if (idx >= 0 && idx < 4){
        if (this->_bag[idx] != NULL){
            this->_bag[idx]->use(target);
        }
    }
}

