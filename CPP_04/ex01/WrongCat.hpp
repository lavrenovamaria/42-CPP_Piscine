#ifndef WCAT_HPP
# define WCAT_HPP

# include <iostream>
# include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
    public:
        WrongCat();
        WrongCat(const WrongCat &src);
        ~WrongCat();

        WrongCat &operator=(const WrongCat &newValue);
        virtual void makeSound() const;
};
#endif
