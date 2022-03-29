#include "Zombie.hpp"

Zombie* ZombieHorde(int N, std::string name)
{
	if (N < 0)
	    return (NULL);

	Zombie *nbrheapZombie = new Zombie[N];

	if (!nbrheapZombie)
	{
	    std::cout << "Cannot allocate memory, smh" << std::endl;
	    return (NULL);
	}
	for (int i = 0; i < N; ++i)
	{
		std::stringstream	str;
		str << (i + 1);
		nbrheapZombie[i].setName(name + "(" + str.str() + ")");
	}
	return (nbrheapZombie);
}



