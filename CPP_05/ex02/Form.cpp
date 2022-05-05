#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(){
	_signed = false;
}

Form::~Form(){

}

Form::Form(Form const &src){
	_gradeToSign = src.getGradeSignature();
	_gradeToExec = src.getGradeExecute();
	_signed = src.getSign();
}

Form& Form::operator=(Form const &src){
	_gradeToSign = src.getGradeSignature();
	_gradeToExec = src.getGradeExecute();
	_signed = src.getSign();
	return (*this);
}

Form::Form(std::string const src, int gradeToSign, int gradeToExec, std::string const new_target):
	_name(src),
	_signed(false),
	_gradeToSign(gradeToSign),
	_gradeToExec(gradeToExec),
	_target(new_target)
{
	if (getGradeSignature() < 1 || getGradeExecute() < 1)
	{
		throw Form::GradeTooHighException();
	}
	else if (getGradeSignature() > 150 || getGradeExecute() > 150)
	{
		throw Form::GradeTooLowException();
	}
}

std::string const Form::getName() const
{
	return (_name);
}

int Form::getGradeExecute() const
{
	return (_gradeToExec);
}

int Form::getGradeSignature() const
{
	return (_gradeToSign);
}

bool Form::getSign() const
{
	return (_signed);
}

std::string const Form::getTarget() const
{
    return (_target);
}

const char *Form::GradeTooHighException::what() const throw(){
	return "чета высоковатый Grade";
}

const char *Form::GradeTooLowException::what() const throw(){
	return "слишком низкий Grade";
}

const char	*Form::FormIsNoSignedException::what() const throw()
{
	return "Form is not signed exception";
}

std::ostream& operator<<(std::ostream &cout, Form const &orig)
{
	cout << orig.getName() << std::endl;

	cout << "Grade, необходимый для подписи " << orig.getGradeSignature() << std::endl;
	cout << "Grade, необходимый для выполнения " << orig.getGradeExecute() << std::endl;

	return (cout);
}

void Form::beSigned(Bureaucrat &obj)
{
	if (obj.getGrade() <= getGradeSignature())
	{
		// <bureaucrat> signs <form>
		_signed = true;
	}
	else
	{
		// <bureaucrat> cannot sign <form> because <reason>
		throw Form::GradeTooLowException();
	}
}

void	Form::execute(Bureaucrat const &executor) const
{
	std::cout << std::endl <<  "Executor '" << executor.getName() << "' is executing '" << this->getName() << "'..." << std::endl;
	if (this->getSign() == false)
		throw Form::FormIsNoSignedException();
	if (executor.getGrade() > this->_gradeToExec)
		throw Form::GradeTooLowException();
	this->execute(executor);
	std::cout << "Executor '" << executor.getName() << "' has executed '" << this->getName() << "'" << std::endl;
}
