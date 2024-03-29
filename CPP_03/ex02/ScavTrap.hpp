#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

// Подкласс(subclass)/производный/дочерний : наследующий свойства другого класса
// Базовый(super class)/родительский : класс, свойства которого наследуются подклассами.

// Наследование для некой модификации
// Производный(Наследние, содержит все свойства базового) и Базовый класс
// Производный класс получает методы и переменные базового класса.
//ScavTrap(дочерний) — наследник класса ClapTrap
//protected, если вы хотите сделать свое свойство/метод видимым
//во всех классах, расширяющих текущий класс, включая родительский класс
class ScavTrap: public ClapTrap
{
	private:
	// приватные переменные и методы не могут быть унаследованы.
	public:
		ScavTrap();
		~ScavTrap();
		ScavTrap(const ScavTrap &src);// копируем класс для других инициализаций и передачи объектов
		// Перегрузка операторов
		// Определила у класса метод с именем (operator=) и констатная ссылка на значение этого типа
		// Возвращаемое значение - это ссылка на текущее значение объекта/экземпляр
		ScavTrap &operator=(const ScavTrap &newValue);
		void guardGate();
	};

#endif
