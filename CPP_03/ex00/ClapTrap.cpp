#include "ClapTrap.hpp"

ClapTrap::ClapTrap(){}
ClapTrap::ClapTrap(std::string name): _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0){}
ClapTrap::ClapTrap(const ClapTrap &arg){
	*this= arg;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &arg){
	_name = arg._name;
	_hitPoints = arg._hitPoints;
	_energyPoints = arg._energyPoints;
	_attackDamage = arg._attackDamage;
	return *this;
}

void ClapTrap::attack(const std::string &target){
	if(_hitPoints > 0 && _energyPoints > 0)
		std::cout << "ClapTrap " << _name << " attacks "<< target << ", causing " << _attackDamage << " points of damage!" << std::endl;
	_energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount){
	_hitPoints -= amount;
	std::cout << "ClapTrap " << _name << " took " << amount << " amount of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount){
	if(_hitPoints > 0 && _energyPoints > 0){
		_hitPoints += amount;
		std::cout << _name << " was repaired!" << std::endl;
	_energyPoints--;
	}
}

ClapTrap::~ClapTrap(){}
