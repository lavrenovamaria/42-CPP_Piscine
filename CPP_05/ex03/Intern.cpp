#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "Intern.hpp"

Intern::Intern(){}
Intern::~Intern(){}
Intern::Intern(Intern const &arg){
	*this = arg;
}

Intern &Intern::operator=(const Intern &arg){
	if(this == &arg)
		return *this;
	return *this;
}

const char *Intern::InternCannotCreateForm::what() const throw(){
	return("Intern cannot create this form");
}

Form *Intern::makeForm(const std::string nameForm, std::string const targetForm){
	std::string array[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
	int i = 0;
		while(i < 3 && array[i] != nameForm)
			i++;
	switch (i)
	{
		case 0:
			std::cout << "Intern creates a form named "<< nameForm << " for " << targetForm << std::endl;
			return (new ShrubberyCreationForm(targetForm));
			break ;
		case 1:
			std::cout << "Intern creates a form named "<< nameForm << " for " << targetForm << std::endl;
			return (new RobotomyRequestForm(targetForm));
			break ;
		case 2:
			std::cout << "Intern creates a form named "<< nameForm << " for " << targetForm << std::endl;
			return (new PresidentialPardonForm(targetForm));
			break ;
		default:
			std::cout << "Intern trying create form "<< nameForm << " for " << targetForm << std::endl;
			throw Intern::InternCannotCreateForm();
			break ;
	}
	return NULL;
}
