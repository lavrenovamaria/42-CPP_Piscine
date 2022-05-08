#include <iostream>
#include "Iter.hpp"

// int main()
// {
// 	char nbr[6] = {'0', '1', '2', '3', '4', '5'};
// 	::iter(nbr, 6, &::f);
// 	std::cout << std::endl;

// 	int i = 0;
// 	char ltr = 'E';
// 	char arr2[6];
// 	while (i < 6)
// 	{
// 		arr2[i] = ltr;
// 		ltr+= 1;
// 		i++;
// 	}
// 	::iter(arr2, 6, &::f);
// 	std::cout << std::endl;
// }

class Awesome
{
	public:
	Awesome( void ) : _n( 42 ) { return; }
	int get( void ) const { return this->_n; }
	private:
	int _n;
	};
	std::ostream & operator<<( std::ostream & o, Awesome const & rhs ) { o << rhs.get(); return o; }
	template< typename T >
	void print( T const & x ) { std::cout << x << std::endl; return; }
	int main() {
	int tab[] = { 0, 1, 2, 3, 4 }; // <--- I never understood why you can't write int[] tab. Wouldn't that make more sense?
	Awesome tab2[5];

	iter( tab, 5, print );
	iter( tab2, 5, print );

	return 0;
}
