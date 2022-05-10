#include "Converter.hpp"
#include <iostream>
#include <string>
#include <exception>
#include <climits>
#include <cmath>

int			main(int argc, char **argv)
{
	Converter	scalar;
	char 		*ptrEnd;
	double 		num;

	try {
		if (argc == 2)
		{
			num = strtod(argv[1], &ptrEnd);
			if (&ptrEnd[0] == &argv[1][0]
			&& static_cast<std::string>(argv[1]).length() == 1)
				num = *ptrEnd;
			if ((isprint(*ptrEnd) && static_cast<std::string>(argv[1]).length() != 1)
			&& !(&ptrEnd[0] != &argv[1][0]
			&& *ptrEnd == 'f'
			&& static_cast<std::string>(ptrEnd).length() == 1))
				throw Converter::impossibleToConvert();
			scalar.setValue(num);
			scalar.convert("int");
			scalar.convert("float");
			scalar.convert("double");
			scalar.convert("char");
		}
		else
			std::cerr << "Error: count argc != 2" << std::endl;
	}
	catch (Converter::impossibleToConvert& e)
	{
		std::cout << "Could not convert string to double representation" << std::endl;
	}
	return (0);
}
