#include <iostream>
#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    type = "WrongCat";
    std::cout << "[WrongCat] Default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &src)
{
    *this = src;
    std::cout << "[WrongCat] Copy constructor called" << std::endl;
}

WrongCat::~WrongCat()
{
    std::cout << "[WrongCat] Destructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &newValue)
{
    this->type = newValue.type;
    std::cout << "[Cat] Assignement operator called" << std::endl;
    return *this;
}

void WrongCat::makeSound() const
{
    std::cout << "WrongAnimal sound" << std::endl;
}
