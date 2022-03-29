#include "Weapon.hpp"

Weapon::Weapon(std::string str)
{
    _type = str;
}

const std::string Weapon::getType() const
{
    return(_type);
}

void  Weapon::setType(std::string new_type) // Установить
{
    // const -> значение переменной не может быть изменено после инициализации
    _type = new_type;
}

Weapon::~Weapon()
{
}
