#include <iostream>
#include "Cat.hpp"

Cat::Cat()
{
    type = "Cat";
    brain = new Brain();
    std::cout << "[Cat] Default constructor called" << std::endl;
}

Cat::Cat(const Cat &src)
{
    *this = src;
    std::cout << "[Cat] Copy constructor called" << std::endl;
}

Cat::~Cat()
{
    std::cout << "[Cat] Destructor called" << std::endl;
    delete brain;
}

Cat &Cat::operator=(const Cat &newValue)
{
    this->type = newValue.type;
    int i = 0;
    while (i < 100)
    {
        this->brain[i] = newValue.brain[i];
        i++;
    }
    std::cout << "[Cat] Assignement operator called" << std::endl;
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
