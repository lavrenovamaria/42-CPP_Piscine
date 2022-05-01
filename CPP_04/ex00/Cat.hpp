#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include "Animal.hpp"

class Cat: public Animal
{
    public:
        Cat();
        Cat(const Cat &src);// копируем класс для других инициализаций и передачи объектов
        ~Cat();

        Cat &operator=(const Cat &newValue);
        void makeSound() const;
};

#endif
