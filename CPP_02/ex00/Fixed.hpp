#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int _n_value;
		static const int _fractional_bit = 8;

	public:
		Fixed();
		~Fixed();

		Fixed(const Fixed &arg);
		Fixed& operator= (const Fixed &arg);

		int getRawBits(void) const;
		void setRawBits(int const raw);
};

#endif
