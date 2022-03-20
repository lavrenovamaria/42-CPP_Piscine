#include <iostream>

int	main(int argc, char **argv)
{
	int		i;
	size_t	j;

	i = 1;
	j = 0;
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
		return (0);
	}
	for (i = 1; argv[i]; i++)
	{
		for (j = 0; argv[i][j]; j++)
			std::cout << (char)toupper(argv[i][j]);
	}
	std::cout << std::endl;
	return (0);
}
