#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <iostream>
# include <sstream>

class Zombie
{
	private:
		std::string _name;
	public:
		Zombie();
		Zombie(std::string name);
		~Zombie();
		void	setName(std::string name);
		void	announce();
};

Zombie* ZombieHorde(int N, std::string name);

#endif
