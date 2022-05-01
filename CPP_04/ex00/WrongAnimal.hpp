#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal
{
	protected:
		std::string type;
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal &src);
		~WrongAnimal();

		WrongAnimal     &operator=(const WrongAnimal &newValue);
		std::string     getType() const;
		void    makeSound() const;
};

#endif
