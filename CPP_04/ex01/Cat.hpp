#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class Cat: public Animal
{
    private:
        Brain *brain;
    public:
        Cat();
        Cat(const Cat &src);
        ~Cat();

        Cat &operator=(const Cat &newValue);
        virtual void makeSound() const;
        virtual Brain   *getBrain() const;
};
#endif
