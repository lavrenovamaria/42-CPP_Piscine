#include "Bureaucrat.hpp"
#include "Form.hpp"
// Исключение (exception)

int main()
{
	std::cout << std::endl;

	Form blank("[Его величество документ №123]", 4, 18);
	std::cout << "Form : " << blank << std::endl;
// 4 число — grade, необходимый для подписания
// 18 число — grade, необходимый для выполнения
	Bureaucrat a1("Mister Kek", 0);
	Bureaucrat b1("Mista Lol", 16);
	Bureaucrat c1("Fella", 80);

	std::cout << "-------------------" << std::endl;

	try
	{
		a1.beSigned(blank);
		std::cout << "---------------" << std::endl;

		b1.beSigned(blank);
		std::cout << "---------------" << std::endl;

		c1.beSigned(blank);
		std::cout << "---------------" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
