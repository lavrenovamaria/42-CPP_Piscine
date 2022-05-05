#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include "Form.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
{

}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &orig): 
Form(orig)
{

}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const &orig)
{
    Form::operator=(orig);
	return (*this); 
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) :
Form("New_ShrubberyCreationForm", 145, 137, target)
{
	
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor)const
{
	if (executor.getGrade() <= getGradeExecute())
	{
		std::string("   gxgxgg    ggxgg\n") + \
		std::string("  ggxgxg gg  gxgxggg\n") + \
		std::string(" gggg xxgxgg ggg gggx\n") + \
		std::string(" gxg g gxgxg  xgxxgxg\n") + \
		std::string("  gxg xggxgggg g ggg\n") + \
		std::string("     gggg  /g/g\n") + \
		std::string("         o  oo /\n") + \
		std::string("          |   /\n") + \
		std::string("          |  |\n") + \
		std::string("          | D|\n") + \
		std::string("          |  |\n") + \
		std::string("          |  |\n") + \
		std::string("   ______/___|___\n");
	}
	else
		throw std::string("Бюрократ имеет слишком низкий grade");
}