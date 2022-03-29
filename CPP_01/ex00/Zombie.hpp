#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
//Поведение функций класса лучше определять в cpp, а не в hpp
class Zombie
{
	private:
		std::string _name;
	public:
		Zombie(std::string name);//вывод "Name of the Zombie: "
		~Zombie();//вызов деструктора
		void    announce();//скажет BraiiiiiiinnnzzzZ...
};

Zombie* newZombie(std::string name);//heap
void    randomChump(std::string name);//stack

#endif
