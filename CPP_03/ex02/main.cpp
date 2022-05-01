#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{

	ClapTrap A;
	ClapTrap B("ClapTrap");
	ScavTrap R;
	FragTrap F("FragTrap");

	A.setAttackDamage(4);
	B.setAttackDamage(7);
	R.guardGate();
	F.highFivesGuys();

	A.attack("TARGET A");
	B.attack("TARGET B");
	R.attack("TARGET R");
	F.attack("TARGET F");

	A.takeDamage(5);
	B.takeDamage(8);
	R.takeDamage(7);
	F.takeDamage(21);


	A.beRepaired(1);
	B.beRepaired(6);
	R.beRepaired(10);
	F.beRepaired(42);

	A.takeDamage(5);
	B.takeDamage(11);
	R.takeDamage(50);

	A.beRepaired(10);
	B.beRepaired(15);

	A.beRepaired(10);
	A.beRepaired(10);
	A.beRepaired(10);
	A.beRepaired(10);
	A.beRepaired(10);
	A.beRepaired(10);

	A.takeDamage(5);
	F.takeDamage(200);
	A.attack("TARGET A");
	A.attack("TARGET A");

	R.attack("TARGET R");
	R.attack("TARGET R");
	R.attack("TARGET R");
	R.attack("TARGET R");
	F.beRepaired(400);
	F.attack("TARGET F");

	return 0;
}
