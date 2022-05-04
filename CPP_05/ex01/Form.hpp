#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Form
{
	private:
			std::string const	_name;
			bool				_signed;//подписано или нет
			int					_gradeToSign;//сколько нужно чтобы подписать
			int					_gradeToExec;//сколько нужно чтобы выполнить
	public:
			Form();
			~Form();
			Form(Form const &src);//копирует класс
			//для инициализаций других и передачи объектов
			Form& operator=(Form const &src);
			//Верну ссылку на текущее значение объекта/экземпляр
			Form(std::string const &src, const int gradeToSign, const int gradeToExec);
			std::string const getName() const;
			int getGradeSignature() const;
			int getGradeExecute() const;
			bool getSign() const;
			void beSigned(Bureaucrat &obj);
			class GradeTooHighException: public std::exception
			{
				public:
						virtual const char *what() const throw();
			};
			class GradeTooLowException: public std::exception
			{
				public:
						virtual const char *what() const throw();
			};
};
std::ostream& operator<<(std::ostream &cout, Form const &src);
//Перегрузка << оператора для ostream, который выводит что-то
//<name>, Form grade <grade>


#endif
