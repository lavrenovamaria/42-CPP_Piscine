#include "Zombie.hpp"

int main()
{
	Zombie *horde = ZombieHorde(5, "zombie_ay");

	if (!horde)
	{
		std::cout << "Cannot allocate memory, smh" << std::endl;
		return (-1);
	}

	std::cout <<  "Check horde: " << horde << std::endl;
	for (int i = 0; i < 5; i++)
		horde[i].announce();
	delete[] horde;

	return (0);
}
