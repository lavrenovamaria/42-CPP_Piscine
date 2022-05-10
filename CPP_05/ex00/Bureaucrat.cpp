#include "Bureaucrat.hpp"

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
	return "Grade too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw(){
	return "Grade too low";
}

std::ostream& operator<<(std::ostream &cout, Bureaucrat const &src){
	cout << "[BUREAUCRAT]" << std::endl;
	cout << src.getName() << std::endl;
	cout << src.getGrade() << std::endl;
	return cout;
}
