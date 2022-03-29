#include "Zombie.hpp"

Zombie *newZombie(std::string name)
{
	Zombie *person = NULL;
	person = new Zombie(name);//динамически запрашивает память в free store
	if(!person)//если вернет null - память не выделяется
		std::cout << "Cannot allocate memory, smh" << std::endl;
	return(person);
}
//отличие heap от free store чисто концептуальное
//одна баночка для хранения печенья, другая для хранения жуков
//new and delete - free store
//malloc and free - heap
