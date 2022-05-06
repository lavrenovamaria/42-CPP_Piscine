#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>

template <typename T>
class Array
{
	private:
		T *arraySecond;
		unsigned int len;
	public:
		Array() {};
		~Array() {
			if (arraySecond)
				delete[]arraySecond;
		};
		Array(unsigned int n)
		{
			len = n;
			arraySecond = new T[n];
		};
		Array(Array const &src)
		{
			len = src.len;
			for(int i = 0; i < len; i++)
				arraySecond[i] = src.array[i];
		};
		Array& operator=(Array const &src)
		{
			if (this != &src)
			{
				len = src.len;
				arraySecond = src.array;
			}
			return (*this);
		};
		T& operator[](unsigned int index)
		{
			if (index < 0 || index > len)
				throw OutOfBoundsException();
			return (arraySecond[index]);
		};
		class OutOfBoundsException : public std::exception
		{
			public :
				virtual const char* what() const throw()
				{
					return ("ArrayException: index out of bounds");
				}
		};
		unsigned int size() 
		{
			return (len);
		};
};

#endif