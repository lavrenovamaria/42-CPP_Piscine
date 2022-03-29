#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"
// #include <iostream>

class HumanB
{
    private:
        std::string _name; // имя
        Weapon *_weapon;// оружие
        // функция атаки;
    public:
        HumanB(std::string);

        ~HumanB();

        void attack();

        void setWeapon(Weapon &weap);

};

#endif
