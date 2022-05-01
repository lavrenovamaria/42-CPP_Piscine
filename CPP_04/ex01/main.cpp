#include <iostream>
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    int arraySize = 5;
    int i = 0;

    Animal  *animals[arraySize];
    while (i < arraySize)
    {
        if (i % 2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
        i++;
    }

    std::cout << "----------------" << std::endl;
    Brain *brain = animals[2]->getBrain();
	brain->ideas[0] = "EAT";
	brain->ideas[1] = "SLEEP";
	brain->ideas[2] = "Zzzzz";
	std::cout << animals[2]->getBrain()->ideas[2] << std::endl;

    std::cout << "----------------" << std::endl;
	animals[3]->makeSound();
	animals[4]->makeSound();
	std::cout << "Type: " << animals[2]->getType() << std::endl;

    std::cout << "----------------" << std::endl;
    std::cout << animals[2]->getType() << std::endl;
	*(animals[2]) = *(animals[3]);
    std::cout << animals[3]->getType() << std::endl;
	std::cout << animals[2]->getType() << std::endl;

    std::cout << "----------------" << std::endl;
    i = 0;
    while (i < arraySize)
    {
        delete animals[i];
        i++;
    }
    return 0;
}
