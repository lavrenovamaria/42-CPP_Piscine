#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>	  // std::setw

class Contact{ // Определение нового класса Contact и список его компонентов
	private: 	// private — доступны в пределах самого объявленного класса
		std::string _first_name;
		std::string _last_name; // свойство класса
		std::string _nickname;
		std::string _phone_number;
		std::string _darkest_secret;
	public:		// public — свойства и методы класса доступны вне класса
		Contact(std::string name, // Прототип члена функции
				std::string l_name,  // :: -> определение члена функции
				std::string nick,
				std::string phone,
				std::string secret);
		Contact();
		 // Дефолтный/Пустой конструктор для использования и создания какой-либо переменной
		std::string getFname() const;
		std::string getLname() const;
		std::string getNick() const;
		std::string getPhone() const;
		std::string getSecret() const;

};//что в фигурных скобках это тело класса

class PhoneBook {
	public:
		Contact mas[8];

	void header_for_three()
	{
		std::cout << std::setw(10) << "  index   |"
		<< std::setw(10) << "  f_name  |"
		<< std::setw(10) << "  l_name  |"
		<< std::setw(10) << "   nick   |" << std::endl;
		std::cout << "————————————————————————————————————————————" << std::endl;
	}

	void header_for_all()
	{
		std::cout << std::setw(10) << "  index   |"
		<< std::setw(10) << "  f_name  |"
		<< std::setw(10) << "  l_name  |"
		<< std::setw(10) << "   nick   |"
		<< std::setw(10) << "   phone  |"
		<< std::setw(10) << "  secret  |" << std::endl;
		std::cout << "——————————————————————————————————————————————————————————————————" << std::endl;
	}
};

#endif
