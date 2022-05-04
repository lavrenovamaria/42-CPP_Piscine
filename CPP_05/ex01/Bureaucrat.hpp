#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

class Form;

class Bureaucrat
{
	private:
			std::string _name;
			int			_grade;
			//1 - highest(самая высокая оценка)
			//150 - lowest(самая низкая оценка)
	public:
			Bureaucrat();
			~Bureaucrat();
			Bureaucrat(Bureaucrat const &src);//копирует класс
			//для инициализаций других и передачи объектов
			Bureaucrat& operator=(Bureaucrat const &src);
			//Верну ссылку на текущее значение объекта/экземпляр
			Bureaucrat(const std::string name, int grade);
			std::string const getName() const;
			int getGrade() const;

			void increaseGrade();// увеличить +
			void decreaseGrade();// уменьшить -
			//Обработка исключений - исключительных ситуаций в работе программы
			//std::exception - базовый клас с++ обрабатывающий исключения
			//Все классы обработки исключений создаются путем наследования его
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
			void  beSigned(Form &obj);
};
std::ostream& operator<<(std::ostream &cout, Bureaucrat const &src);
//Перегрузка << оператора для ostream, который выводит что-то
//<name>, Bureaucrat grade <grade>
#endif
