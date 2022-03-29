#include "phonebook.hpp"

void	push_new_str(std::string str)
{
	std::string new_s;

	if (str.length() < 10)
		std::cout << std::setw(10) << str << "|";
	else
	{
		new_s = str.substr(0, 9);
		new_s.push_back('.');
		std::cout << new_s << "|";
	}
}

void	print_base_list(Contact mas, int num)
{
	std::cout << std::setw(10) << num << "|";
	push_new_str(mas.getFname());
	push_new_str(mas.getLname());
	push_new_str(mas.getNick());
	push_new_str(mas.getPhone());
	push_new_str(mas.getSecret());
}

void	print_list(Contact mas)
{
	push_new_str(mas.getFname());
	push_new_str(mas.getLname());
	push_new_str(mas.getNick());
}

void	search_person(int i, PhoneBook *ph)
{
	int count;

	ph->header_for_three();
	count = 0;

	while(count < i)
	{
		std::cout << std::setw(10) << count << "|";
		print_list(ph->mas[count]);
		std::cout << std::endl;
		count++;
	}
}

void	add_person(int i, PhoneBook *ph, int &more)
{
	std::string s0, s1, s2, s3, s4;

	std::cout << "first name: ";
	std::cin >> s0;
	std::cout << "last name: ";
	std::cin >> s1;
	std::cout << "nickname: ";
	std::cin >> s2;
	std::cout << "phone number: ";
	std::cin >> s3;
	std::cout << "darkest secret: ";
	std::cin >> s4;

	Contact new_person;
	new_person = Contact(s0, s1, s2, s3, s4);

	if (i < 8)
		ph->mas[i] = new_person;
	else
	{
		ph->mas[more] = new_person;
		more++;
		if (more == 8)
			more = 0;
	}
}

int	check_valid_arg(std::string str)
{
	if (str.length() > 1 || !std::isdigit(str[0]))
		return (-1);
	return (0);
}

void	other_personal_search(int i, PhoneBook *ph)
{
	int	num_in;
	std::string str;

	std::cin >> str;
	if (check_valid_arg(str) == -1)
	{
		std::cout << "incorrect format" << std::endl;
		return ;
	}
	num_in = std::atoi(str.c_str());
	if (num_in < 0 || num_in > 7 || num_in >= i )
	{
		std::cout << "incorrect format" << std::endl;
		return ;
	}
	else
	{
		ph->header_for_all();//указательн на объекты
		print_base_list(ph->mas[num_in], num_in);
		std::cout << std::endl;
	}
}

int main()
{
	int	overflow;
	std::string s;//оператор разрешения области видимости
	PhoneBook ph;

	overflow = 0;
	int index = 0;
	std::cout << "📞 Hello, this is wrickard's Phonebook" << std::endl;
	while (1)
	{
		std::cout << "Save Contact   : ADD" << std::endl;
		std::cout << "Search Contact : SEARCH" << std::endl;
		std::cout << "Contact End    : EXIT" << std::endl;
		std::cout << "Enter command  : ";
		std::cin >> s;
		if (s == "EXIT")
		{
			std::cout << "finish" << std::endl;
			break ;
		}
		else if (s == "ADD")
		{
			add_person(index, &ph, overflow);
			if (index < 8)
				index++;
		}
		else if (s == "SEARCH")
		{
			search_person(index, &ph);
			std::cout << "index of contact ";
			other_personal_search(index, &ph);
		}
		else
			std::cout << "error" << std::endl;
	}
	return (0);
}
