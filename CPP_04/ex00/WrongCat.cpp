#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	type = "WrongCat";
    std::cout << "WrongCat стандартный конструктор" << std::endl;
}

WrongCat::WrongCat(const WrongCat &src)
{
    *this = src;
    std::cout << "WrongCat конструктор копирования" << std::endl;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat деструктор" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &newValue)
{
	if(this != &newValue) // 2 одинаковых объекта
		this->type = newValue.type;
    std::cout << "WrongCat оператор '=' клонирует" << type << std::endl;
    return *this;
	// Разыменовываем this и получаем ссылку на текущий экземпляр объекта
}

void    WrongCat::makeSound() const
{
    std::cout << "Непонятные звуки непонятного кота" << std::endl;
}
