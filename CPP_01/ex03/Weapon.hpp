#include <iostream>

#ifndef WEAPON_HPP
# define WEAPON_HPP

class Weapon
{
	private:
		std::string _type;

	public:
		Weapon(std::string str);

		const std::string getType() const; // Получить

		void  setType(std::string new_type); // Установить

		~Weapon();
};
#endif
