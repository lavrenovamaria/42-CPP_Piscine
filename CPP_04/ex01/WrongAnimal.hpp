#ifndef WANIMAL_HPP
# define WANIMAL_HPP

# include <iostream>

class WrongAnimal
{
    protected:
        std::string type;
    public:
        WrongAnimal();
        WrongAnimal(const WrongAnimal &src);
        ~WrongAnimal();

        WrongAnimal          &operator=(const WrongAnimal &newValue);
        std::string     getType() const;
        virtual void    makeSound() const;
};
#endif
