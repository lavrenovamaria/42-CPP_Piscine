#include <iostream>
#include "Dog.hpp"

Dog::Dog()
{
    type = "Dog";
    brain = new Brain();
    std::cout << "[Dog] Default constructor called" << std::endl;
}

Dog::Dog(const Dog &src)
{
    *this = src;
    std::cout << "[Dog] Copy constructor called" << std::endl;
}

Dog::~Dog()
{
    std::cout << "[Dog] Destructor called" << std::endl;
    delete brain;
}

Dog &Dog::operator=(const Dog &newValue)
{
    this->type = newValue.type;
    std::cout << "[Dog] Assignement operator called" << std::endl;
    return *this;
}

void Dog::makeSound() const
{
    std::cout << "GAFFF" << std::endl;
}

Brain   *Dog::getBrain() const
{
    return this->brain;
}
