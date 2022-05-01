#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class Dog: public Animal
{
    private:
        Brain *brain;
    public:
        Dog();
        Dog(const Dog &src);
        ~Dog();

        Dog &operator=(const Dog &newValue);
        virtual void makeSound() const;
        virtual Brain   *getBrain() const;
};
#endif
