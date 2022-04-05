#include "Fixed.hpp"

int	main(void)
{
	Fixed a;
	Fixed b(a); // копия объекта (b) из объекта (а)
	Fixed c;

	c = b; // вызывает перегруженное присваивание

	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	return 0;
}
