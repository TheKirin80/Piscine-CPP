#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
    for (int i = 0; i < 4 ; i++){
        this->_inventory[i] = NULL;
    }
    std::cout << "MateriaSource Default Constructor" << std::endl;
    return;
}
MateriaSource::MateriaSource(const MateriaSource &cop)
{
    for (int i = 0; i < 4 ; i++){ 
        if (this->_inventory[i] != NULL){
            delete this->_inventory[i];
            this->_inventory[i] = NULL;
        }
        if (cop._inventory[i] != NULL)
            this->_inventory[i] = cop._inventory[i];
    }
    std::cout << "MateriaSource Recopy Constructor" << std::endl;
}
MateriaSource &MateriaSource::operator=(const MateriaSource &eg)
{
    for (int i = 0; i < 4 ; i++){
        if (this->_inventory[i] != NULL){
            delete this->_inventory[i];
            this->_inventory[i] = NULL;
        }
        if (eg._inventory[i] != NULL){ // Rempli le sac si le sac modele n'est pas vide
            this->_inventory[i] = eg._inventory[i];
        }
    }
    std::cout << "Copy assignment operator MateriaSource called" << std::endl;
    return (*this);
}
MateriaSource::~MateriaSource(void)
{
    for (int i = 0; i < 4 ; i++){
        if (this->_inventory[i] != NULL){
            delete this->_inventory[i];
            this->_inventory[i] = NULL;
        }
    }
    std::cout << "MateriaSource Default Destructor" << std::endl;
    return;
}
void        MateriaSource::learnMateria(AMateria* m)
{
    for (int i = 0; i < 4 ; i++){
        if (this->_inventory[i] == NULL){
            this->_inventory[i] = m;
            std::cout << "Learn Successful" << std::endl;
            return;
        }
    }
}
AMateria*   MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4 ; i++){
        if (this->_inventory[i]->getType() == type){
            return (this->_inventory[i]->clone());
        }
    }
    return (0);
}
