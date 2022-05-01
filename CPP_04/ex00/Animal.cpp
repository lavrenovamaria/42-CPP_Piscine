#include "Animal.hpp"

Animal::Animal()
{
    std::cout << "Animal стандартный конструктор" << std::endl;
}

Animal::Animal(const Animal &src)
{
    *this = src;
    std::cout << "Animal конструктор копирования" << std::endl;
}

Animal::~Animal()
{
    std::cout << "Animal деструктор" << std::endl;
}

Animal &Animal::operator=(const Animal &newValue)
{
	if(this != &newValue) // 2 одинаковых объекта
		this->type = newValue.type;
    std::cout << "Animal оператор '=' клонирует" << type << std::endl;
    return *this;
	// Разыменовываем this и получаем ссылку на текущий экземпляр объекта
}
std::string Animal::getType() const
{
    return type;
}

void    Animal::makeSound() const
{
    std::cout << "У меня нет звука, я никакое животное" << std::endl;
}
