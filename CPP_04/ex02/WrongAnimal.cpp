#include <iostream>
#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    std::cout << "[WrongAnimal] Default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &src)
{
    *this = src;
    std::cout << "[WrongAnimal] Copy constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "[WrongAnimal] Destructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &newValue)
{
    this->type = newValue.type;
    std::cout << "[WrongAnimal] Assignement operator called" << std::endl;
    return *this;
}
std::string WrongAnimal::getType() const
{
    return type;
}

void    WrongAnimal::makeSound() const
{
    std::cout << std::endl;
}
