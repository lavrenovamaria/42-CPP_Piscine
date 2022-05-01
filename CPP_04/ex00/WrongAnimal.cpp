#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	type = "WrongAnimal";
    std::cout << "WrongAnimal стандартный конструктор" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &src)
{
    *this = src;
    std::cout << "WrongAnimal конструктор копирования" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal деструктор" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &newValue)
{
	if(this != &newValue) // 2 одинаковых объекта
		this->type = newValue.type;
    std::cout << "WrongAnimal оператор '=' клонирует" << type << std::endl;
    return *this;
	// Разыменовываем this и получаем ссылку на текущий экземпляр объекта
}

std::string WrongAnimal::getType() const
{
    return type;
}

void    WrongAnimal::makeSound() const
{
    std::cout << "Непонятные звуки" << std::endl;
}
