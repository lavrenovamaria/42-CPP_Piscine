#include "Harl.hpp"

int	main(int argc, char **argv)
{
	Harl harl;
	(void)argv;

	if (argc < 2)
		std::cout << "[ ERROR ARGS ]" << std::endl;
	if (argc > 1)
	{
		std::string i;
		i = argv[1];
		if(i == "debug" || i == "info" || i == "warning" || i == "error")
		{
			harl.complain("DEBUG");
			harl.complain("INFO");
			harl.complain("WARNING");
			harl.complain("ERROR");
		}
		else
		{
			std::cout << "unknown " << std::endl;
		}
	}
}
