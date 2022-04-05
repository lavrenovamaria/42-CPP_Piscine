 #include "Fixed.hpp"

Fixed::Fixed()
{
	n_int = 0;
	// cout << "\e[0;38;5;157m" << "Default constructor called" << "\e[37;0m" << endl;
}

Fixed::~Fixed()
{
	// cout << "\e[0;38;5;104m" << "Destructor called" << "\e[37;0m" << endl;
}

Fixed::Fixed(const Fixed &arg) // Конструктор копирования
{
    // cout << "\e[0;38;5;183m" << "Copy constructor called" << "\e[37;0m"<< endl;
	*this = arg;
}

Fixed& Fixed::operator= (const Fixed &arg) // Перегруженное присваивание
{
    // cout << "\e[0;38;5;117m" << "Assignation operator called" << "\e[37;0m"<< endl;

	this->n_int = arg.n_int;
    return (*this);
}

int Fixed::getRawBits(void) const
{
    // cout << "\e[0;38;5;227m" << "getRawBits member function called" << "\e[37;0m"<< endl;
	return (n_int);
}

void Fixed::setRawBits(int const raw)
{
	n_int = raw;
}

//// new function
Fixed::Fixed(int value)
{
	this->n_int = value << this->f_bit;
	// cout << "\e[0;38;5;189m" << "Int constructor called" << "\e[37;0m"<< endl;
}

Fixed::Fixed(float bits)
{
	this->n_int = roundf(bits * (1 << this->f_bit));
	// cout << "\e[0;38;5;209m" << "Float constructor called" << "\e[37;0m"<< endl;
}

float Fixed::toFloat(void) const
{
	return((float)this->n_int / (float)(1 << this->f_bit));
}

int Fixed::toInt(void) const
{
	return(this->n_int >> this->f_bit);
}

// ostream – выходной поток
std::ostream& operator<< (std::ostream& cout, const Fixed &point_a)
{
	cout << point_a.toFloat();
	return (cout);
}


//// new function 2
Fixed& Fixed::min(Fixed &val1, Fixed &val2) // вернет ссылку на наименьшее знач.
{
	if (val1 < val2) // берем ссылку , сравниваем
		return (val1);
	return (val2);
}

Fixed& Fixed::max(Fixed &val1, Fixed &val2) // вернет ссылку на наибольшее знач.
{
	if (val1 < val2) // берем ссылку , сравниваем
		return (val2);
	return (val1);
}


Fixed const& Fixed::min(const Fixed &val1, const Fixed &val2)
{
	if (val1 < val2) // берем ссылку , сравниваем
		return (val1);
	return (val2); // возвращаем
}

Fixed const&  Fixed::max(const Fixed &val1, const Fixed &val2)
{
	if (val1 < val2)
		return (val2);
	return (val1);
}

Fixed	Fixed::operator*(Fixed const &val) const
{
	Fixed a;

	a.setRawBits((val.n_int >> Fixed::f_bit) * n_int);
	return(a);
}

Fixed&	Fixed::operator++(void) //++a
{
	setRawBits(++n_int);
	return(*this);
}

Fixed	Fixed::operator++(int) //a++
{
	Fixed	a(*this);

	setRawBits(++n_int); // значение увеличили и сохранили
	return(a);  //но вернули то, которое пришло(установлено до инкрементирования)
}

bool	Fixed::operator>(Fixed const &val) const
{
	return (n_int > val.n_int);
}

bool	Fixed::operator<(Fixed const &val) const
{
	return (n_int < val.n_int);
}


// неиспользуемые операторы

bool	Fixed::operator>=(Fixed const &val) //	>=
{
	return (n_int >= val.n_int);
}

bool	Fixed::operator<=(Fixed const &val) //	<=
{
	return (n_int <= val.n_int);
}

bool	Fixed::operator==(Fixed const &val) // ==
{
	return (n_int == val.n_int);
}

bool	Fixed::operator!=(Fixed const &val)	// !=
{
	return (n_int != val.n_int);
}

//
Fixed	Fixed::operator+(Fixed const &val)	// +
{
	Fixed	a;

	a.setRawBits(val.n_int + n_int); // добавьение аргумента и добавление самого себя
	return(a);
}

Fixed	Fixed::operator-(Fixed const &val)	// -
{
	Fixed	a;

	a.setRawBits(val.n_int - n_int);
	return(a);
}

Fixed	Fixed::operator/(Fixed const &val)	// *
{
	Fixed	a;

	a.setRawBits((n_int << Fixed::f_bit) / val.n_int);
	return(a);
}


//
Fixed&	Fixed::operator--(void) //--a
{
	setRawBits(--n_int); // уменьшенеие выполняется до выполнение кода
	return(*this); // потому указатель *this на себя вернет после добавления значения
}

Fixed	Fixed::operator--(int) //a--
{
	Fixed	a(*this);

	setRawBits(--n_int); // уменьшанм собственное значение, устанавливаем
	return(a); // возращаем зачение до уменьшения
}
