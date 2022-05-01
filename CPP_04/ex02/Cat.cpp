#include <iostream>
#include "Cat.hpp"

Cat::Cat()
{
    std::cout << "[Cat] Default constructor called" << std::endl;
    type = "Cat";
    brain = new Brain();
}

Cat::Cat(const Cat &src)
{
    std::cout << "[Cat] Copy constructor called" << std::endl;
    *this = src;
}

Cat::~Cat()
{
    std::cout << "[Cat] Destructor called" << std::endl;
    delete brain;
}

Cat &Cat::operator=(const Cat &newValue)
{
    std::cout << "[Cat] Assignement operator called" << std::endl;
    type = newValue.getType();
    *brain = *newValue.getBrain();
    return *this;
}

AAnimal &Cat::operator=(const AAnimal &newValue)
{
    std::cout << "[AAnimal] Assignement operator called" << std::endl;
    this->type = newValue.getType();
    *brain = *newValue.getBrain();
    return *this;
}

void Cat::makeSound() const
{
    std::cout << "MURRR" << std::endl;
}

Brain   *Cat::getBrain() const
{
    return this->brain;
}
