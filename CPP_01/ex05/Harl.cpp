#include "Harl.hpp"

Harl::Harl(){}
Harl::~Harl(){}
void Harl::debug(void)
{
	std::cout << "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!" << std::endl;
}
void Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon cost more money. You don't put enough! If you did I would not have to ask for it!" << std::endl;
}
void	Harl::warning()
{
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming here for years and you just started working here last month." << std::endl;
}
void	Harl::error()
{
	std::cout << "This is unacceptable, I want to speak to the manager now." << std::endl;
}
void Harl::complain(std::string level)
{
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	int i = 0;
	for (; levels[i] != level && i <= 4; i++);
	void (Harl::*point_f)(); // указатель на определенную функцию в классе

	switch (i)
	{
		case 0: std::cout << "[ " << level << " ]" << std::endl;
			point_f = &Harl::debug;
			break ;
		case 1: std::cout << "[ " << level << " ]" << std::endl;
			point_f = &Harl::info;
			break;
		case 2: std::cout << "[ " << level << " ]" << std::endl;
			point_f = &Harl::warning;
			break;
		case 3: std::cout << "[ " << level << " ]" << std::endl;
			point_f = &Harl::error;
			break;
		default:
			std::cout << "unknown " << std::endl;
			exit(1);
	}
	(this->*point_f)(); // после выхода из цикла
}
