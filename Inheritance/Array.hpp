#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <exception>
# include <cctype>

template<typename T>
class Array
{
private:
	unsigned int _len;
	T * _array;
public:
	Array();
	Array(unsigned int n);
	Array(Array<T> const &other);
	virtual ~Array();

	class outOfLimits: public std::exception {
		virtual const char* what() const throw();
	};

	Array &operator=(Array const &other);
	T &operator[](unsigned int index);
	T const &operator[](unsigned int index) const;

	unsigned int size(void) const;
};

# include "Array.tpp"

#endif