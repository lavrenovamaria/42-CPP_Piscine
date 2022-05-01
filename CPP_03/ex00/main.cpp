#include <iostream>
#include "ClapTrap.hpp"

int main()
{
	ClapTrap A("Petya");
	ClapTrap B("Vasya");

	A.attack("TARGET A");
	B.attack("TARGET B");

	A.takeDamage(5);
	B.takeDamage(8);

	A.beRepaired(1);
	B.beRepaired(6);

	A.takeDamage(5);
	B.takeDamage(11);

	A.beRepaired(10);
	B.beRepaired(15);

	A.beRepaired(10);
	A.beRepaired(10);
	A.beRepaired(10);
	A.beRepaired(10);
	A.beRepaired(10);
	A.beRepaired(10);

	A.takeDamage(5);
	A.attack("TARGET A");
	A.attack("TARGET A");

	return 0;
}
