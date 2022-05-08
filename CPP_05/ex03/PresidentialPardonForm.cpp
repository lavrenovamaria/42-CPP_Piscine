#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include "Form.hpp"

PresidentialPardonForm::PresidentialPardonForm()
{

}

PresidentialPardonForm::~PresidentialPardonForm()
{

}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &orig)
: Form(orig)
{

}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const &orig)
{
	Form::operator=(orig);
	return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() <= getGradeExecute())
	{
    	std::cout << "Вот тот самый" <<
		executor.getName() << " был помилован Зафодом Библеброксом " << std::endl;
	}
	else
		throw std::string("Бюрократ имеет слишком низкий grade");
}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target) :
Form("New_PresidentialPardonForm", 25, 5, target)
{
	
}