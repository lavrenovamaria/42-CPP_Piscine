#include <iostream>
#include <fstream>
#include <string>

//ofstream - сделать запись в файл(запись), вывода
//ifstream - считать данные из файл(чтение), ввода
int main(int argc, char **argv)
{
	std::string file, str1, str2, new_file;

	if (argc != 4)
	{
		std::cout << "Input three parameters in the following order: a filename and two strings, s1 and s2!" << std::endl;
		return (-1);
	}
	file = argv[1];
	str1 = argv[2];
	str2 = argv[3];

	new_file = argv[1];
	new_file.append(".replace"); // создадим файл новый

	std::ifstream s_input; // создание объекта и подключение файла
	std::ofstream s_output(new_file);

	s_input.open(file);

	if (s_input == 0)
	{
		std::cout << "Empty file" << std::endl;
		return (-1);
	}
	if (!s_input.is_open())
	{
		std::cout << "Can't open file" << std::endl;
		s_input.close();
		return (-1);
	}
	else
	{
		std::string read_s;
		size_t check_pos;

		while (1)
		{
			std::getline(s_input, read_s);
			while (1)
			{
				check_pos = read_s.find(str1);
				if (check_pos == std::string::npos)
				{
					s_output << read_s;
					break ;
				}
				s_output << read_s.substr(0, check_pos);
				s_output << str2;
				read_s = read_s.substr(check_pos + str1.size());
			}
			if (s_input.eof() == true)
				break ;
			s_output << std::endl;
		}
	}
	s_input.close();
	return (0);
}
