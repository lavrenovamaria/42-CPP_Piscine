#include <iostream>
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    const WrongAnimal* w = new WrongCat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    std::cout << meta->getType() << " " << std::endl;
    std::cout << w->getType() << " " << std::endl;

    j->makeSound();
    i->makeSound(); //will output the cat sound! j->makeSound();
    meta->makeSound();
    w->makeSound();
    delete j;
	delete i;
    return 0;
}
