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

Form::Form(std::string const &src, const int gradeToSign, const int gradeToExec) :
	_name(src),
	_signed(false),
	_gradeToSign(gradeToSign),
	_gradeToExec(gradeToExec)
{
	if (getGradeSignature() < 1 || getGradeExecute() < 1){
		throw Form::GradeTooHighException();
	}
	else if (getGradeSignature() > 150 || getGradeExecute() > 150){
		throw Form::GradeTooLowException();
	}
}

std::string const Form::getName() const{
	return (_name);
}

int Form::getGradeExecute() const{
	return (_gradeToExec);
}

int Form::getGradeSignature() const{
	return (_gradeToSign);
}

bool Form::getSign() const{
	return (_signed);
}

const char *Form::GradeTooHighException::what() const throw(){
	return "чета высоковатый Grade";
}

const char *Form::GradeTooLowException::what() const throw(){
	return "слишком низкий Grade";
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
	if (obj.getGrade() <= getGradeSignature()){
		_signed = true;
	}
	else{
		throw Form::GradeTooLowException();
	}
}
