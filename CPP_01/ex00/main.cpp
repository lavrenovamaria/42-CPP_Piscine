#include "Zombie.hpp"

int main()
{
	Zombie stackZombie = Zombie("stackZombie");
	stackZombie.announce();

	Zombie *heapZombie = newZombie("heapZombie");

	std::cout <<  "Check heap: " << heapZombie << std::endl;
	heapZombie->announce(); // проверка что создался

	randomChump("Random_Zombak");
	delete heapZombie;
	heapZombie = 0;
	std::cout <<  "Check heap after delete: " << heapZombie << std::endl;

	return(0);
}
//Два способа объявить зомби
//Zombie stackZombie = Zombie("stackZombie");
//Zombie *heapZombie = newZombie("heapZombie");
//[text area]
//где хранится код программы, которую мы запускаем
//[data]
//область где хранится global and static variables
//[stack]
//Local variables and parameters related
//to the invocation of the function are stored
//[heap]
