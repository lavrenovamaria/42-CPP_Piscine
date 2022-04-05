#include "Fixed.hpp"

Fixed::Fixed()
{
	_n_value = 0;
	std::cout  << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout  << "Destructor called"  << std::endl;
}

Fixed::Fixed(const Fixed &arg) // Конструктор копирования
{
    std::cout  << "Copy constructor called" << std::endl;
	*this = arg;
}

Fixed& Fixed::operator= (const Fixed &arg) // Перегруженное присваивание
{
    std::cout <<  "Assignation operator called" <<  std::endl;
    this->_n_value = arg.getRawBits();
    return (*this);
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
	return (_n_value);
}

void Fixed::setRawBits(int const raw)
{
	_n_value = raw;
}
