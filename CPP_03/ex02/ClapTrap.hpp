#pragma once
#include <iostream>

class ClapTrap{
	protected:
		std::string _name;
		int _hitPoints;
		int _energyPoints;
		int _attackDamage;
	public:
		ClapTrap();
		~ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &arg);
		ClapTrap &operator=(const ClapTrap &arg);
		void setAttackDamage(unsigned int attackDamage);
		void attack(const std::string &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};
