#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>

template <typename T>
class Array
{
	private:
		T *array2;
		unsigned int len;
	public:
		Array() {};
		~Array() {
			if (array2)
				delete[]array2;
		};
		Array(unsigned int n)
		{
			len = n;
			array2 = new T[n];
		};
		Array(Array const &orig)
		{
			len = orig.len;
			int i = 0;
			while(i < len)
			{
				array2[i] = orig.array[i];
				i++;
			}
		};
		Array& operator=(Array const &orig)
		{
			if (this != &orig)
			{
				len = orig.len;
				array2 = orig.array;
			}
				
			return (*this);
		};

		T& operator[](unsigned int index)// Перегрузка оператора индексации
		{
			if (index < 0 || index > len)
				throw OutOfBoundsException();
			return (array2[index]);
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