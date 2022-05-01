#include "Cat.hpp"

Cat::Cat()
{
	type = "Cat";
    std::cout << "Cat стандартный конструктор" << std::endl;
}

Cat::Cat(const Cat &src)
{
    *this = src;
    std::cout << "Cat конструктор копирования" << std::endl;
}

Cat::~Cat()
{
    std::cout << "Cat деструктор" << std::endl;
}

Cat &Cat::operator=(const Cat &newValue)
{
	if(this != &newValue) // 2 одинаковых объекта
		this->type = newValue.type;
    std::cout << "Cat оператор '=' клонирует" << type << std::endl;
    return *this;
	// Разыменовываем this и получаем ссылку на текущий экземпляр объекта
}

void    Cat::makeSound() const
{
    std::cout << "Мяу-мяу" << std::endl;
}
