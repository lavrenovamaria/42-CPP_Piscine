
#include "Fixed.hpp"

Fixed::Fixed() : _fix_p_value()
{
	_fix_p_value = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int fixedPointValue) : _fix_p_value(fixedPointValue << this->_n_fr_bits)
{
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float floatingPointValue) : _fix_p_value(roundf(floatingPointValue * pow(2, this->_n_fr_bits)))
{
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &src)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int     Fixed::getRawBits() const
{
    return this->_fix_p_value;
}

void    Fixed::setRawBits(int const raw)
{
    this->_fix_p_value = raw;
}

int     Fixed::toInt() const
{
    return (this->_fix_p_value >> this->_n_fr_bits);
}

float   Fixed::toFloat() const
{
    return (this->_fix_p_value / pow(2, this->_n_fr_bits));
}

Fixed   &Fixed::operator=(Fixed const &rhs)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs)
        this->_fix_p_value = rhs.getRawBits();
    return *this;
}

std::ostream &operator<<(std::ostream &o, Fixed const &value)
{
    o << value.toFloat();
    return o;
}
