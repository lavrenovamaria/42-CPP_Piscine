#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"
// Наследование для некой модификации
// Производный(Наследние, содержит все свойства базового) и Базовый класс
class FragTrap: public ClapTrap // FragTrap — наследник класса ClapTrap
{
private:
	FragTrap();
public:
	FragTrap(std::string name);
	~FragTrap();
	FragTrap(const FragTrap &src);

	FragTrap &operator=(const FragTrap &newValue);
	void highFivesGuys();
};
#endif
