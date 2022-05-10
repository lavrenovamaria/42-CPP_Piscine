#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
	Intern intern;
	Form*  nameForm1;
	try
	{
		nameForm1 = intern.makeForm("ShrubberyCreationForm", "Shrubbery for you");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	Form*  nameForm2;
	try
	{
		nameForm2 = intern.makeForm("RobotomyRequestForm", "Love death and some cutie robot");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	Form*  nameForm3;
	try
	{
		nameForm3 = intern.makeForm("PresidentialPardonForm", "My pardon");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	Form*  nameForm4;
	try
	{
		nameForm4 = intern.makeForm("None", "NoneForm");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

