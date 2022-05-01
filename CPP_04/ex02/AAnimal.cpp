#include <iostream>
#include "AAnimal.hpp"

AAnimal::~AAnimal()
{
    std::cout << "[AAnimal] Destructor called" << std::endl;
}

std::string AAnimal::getType() const
{
    return type;
}
