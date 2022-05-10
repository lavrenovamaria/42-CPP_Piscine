#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(){}

Bureaucrat::~Bureaucrat(){}

Bureaucrat::Bureaucrat(Bureaucrat const &src){
	_grade = src.getGrade();
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const &src){
	_grade = src.getGrade();
	return(*this);
	//мы разыменуем this и получим ссылку на текущий экземпляр объекта
}

Bureaucrat::Bureaucrat(const std::string name, int grade): _name(name), _grade(grade){
	if (getGrade() < 1){
		throw Bureaucrat::GradeTooHighException();
	}
	else if(getGrade() > 150){
		throw Bureaucrat::GradeTooLowException();
	}
}

void Bureaucrat::decreaseGrade(){
	_grade--;
}

void Bureaucrat::increaseGrade(){
	_grade++;
}

std::string const Bureaucrat::getName() const
{
	return _name;
}

int Bureaucrat::getGrade() const
{
	return _grade;
}

const char *Bureaucrat::GradeTooHighException::what() const throw(){
	return "Бюрократ имеет слишком высокий Grade";
}

const char *Bureaucrat::GradeTooLowException::what() const throw(){
	return "Бюрократ имеет слишком низкий Grade";
}

std::ostream& operator<<(std::ostream &cout, Bureaucrat const &src){
	cout << "[BUREAUCRAT]" << std::endl;
	cout << src.getName() << std::endl;
	cout << src.getGrade() << std::endl;
	return cout;
}

void  Bureaucrat::beSigned(Form &obj){
	try{
		obj.beSigned(*this);
		std::cout << _name << " подписывает форму " << obj.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		if (getGrade() <= obj.getGradeExecute() && getGrade() >= obj.getGradeSignature()){
			std::cout << _name << " не может подписать форму " << obj.getName() << std::endl;
			std::cout << "потому что для " << obj.getName() << std::endl;
		}
		else{
			std::cout << _name << " не может выполнить форму " << obj.getName() << std::endl;
			std::cout  << "потому что для " << obj.getName() << std::endl;
		}
		std::cerr << e.what() << '\n';
	}
}
