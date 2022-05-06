#include <iostream>
#include "Iter.hpp"

int main()
{
	char nbr[6] = {'0', '1', '2', '3', '4', '5'};
	::iter(nbr, 6, &::f);
	std::cout << std::endl;

	int i = 0;
	char ltr = 'E';
	char arr2[6];
	while (i < 6)
	{
		arr2[i] = ltr;
		ltr+= 1;
		i++;
	}
	::iter(arr2, 6, &::f);
	std::cout << std::endl;
}