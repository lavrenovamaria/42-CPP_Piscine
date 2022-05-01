#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include "AAnimal.hpp"
# include "Brain.hpp"

class Cat: public AAnimal
{
    private:
        Brain *brain;
    public:
        Cat();
        Cat(const Cat &src);
        ~Cat();

        Cat             &operator=(const Cat &newValue);
        virtual AAnimal &operator=(const AAnimal &newValue);
        virtual void     makeSound() const;
        virtual Brain   *getBrain() const;
};
#endif
