#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>

template <typename T>
class Array
{
	private:
		T *_array;
		unsigned int _len;
	public:
		Array() {};
		~Array() {
			if (_array)
				delete[]_array;
		};
		Array(unsigned int n){
			_len = n;
			_array = new T[n]();
		};
		Array(Array const &src){
			_len = src._len;
			for(int i = 0; i < _len; i++)
				_array[i] = src.array[i];
		};
		Array& operator=(Array const &src){
			if (this != &src){
				_len = src._len;
				_array = src.array;
			}
			return (*this);
		};
		T& operator[](unsigned int index){
			if (index < 0 || index > _len)
				throw OutOfBoundsException();
			return (_array[index]);
		};
		class OutOfBoundsException : public std::exception{
			public :
				virtual const char* what() const throw()
				{
					return ("ArrayException: index out of bounds");
				}
		};
		unsigned int size() {
			return (_len);
		};
};

#endif
