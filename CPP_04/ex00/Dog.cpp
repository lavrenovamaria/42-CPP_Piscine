#include "Dog.hpp"

Dog::Dog()
{
	type = "Dog";
    std::cout << "Dog стандартный конструктор" << std::endl;
}

Dog::Dog(const Dog &src)
{
    *this = src;
    std::cout << "Dog конструктор копирования" << std::endl;
}

Dog::~Dog()
{
    std::cout << "Dog деструктор" << std::endl;
}

Dog &Dog::operator=(const Dog &newValue)
{
	if(this != &newValue) // 2 одинаковых объекта
		this->type = newValue.type;
    std::cout << "Dog оператор '=' клонирует" << type << std::endl;
    return *this;
	// Разыменовываем this и получаем ссылку на текущий экземпляр объекта
}

void    Dog::makeSound() const
{
    std::cout << "Гав-гав" << std::endl;
}
