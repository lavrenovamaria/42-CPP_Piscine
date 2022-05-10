#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include "Form.hpp"

RobotomyRequestForm::RobotomyRequestForm(){}

RobotomyRequestForm::~RobotomyRequestForm(){}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &orig)
: Form(orig)
{}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const &orig)
{
	Form::operator=(orig);
	return (*this);
}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) :
Form("New_RobotomyRequestForm", 72, 45, target)
{}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() <= getGradeExecute())
	{
		std::cout << "Drrr drrr drrr '" << getTarget() << "' has been robotomized successfully 50\% of the time" << std::endl;
	}
	else
		throw std::string("Бюрократ имеет слишком низкий grade");
}
