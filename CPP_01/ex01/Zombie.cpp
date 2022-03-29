#include "Zombie.hpp"

//Поведение функций класса лучше определять в cpp, а не в hpp
Zombie::Zombie() {};
Zombie::Zombie(std::string x)
{
	_name = x;
	std::cout << "NAME of our friend: " << _name << std::endl;
}

Zombie::~Zombie()
{
    std::cout << _name << " was destroyed" << std::endl;
};

void    Zombie::announce()
{
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void    Zombie::setName(std::string name)
{
    this->_name = name;
};

