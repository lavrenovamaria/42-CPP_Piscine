#ifndef INTERN_HPP
#define INTERN_HPP

#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <exception>

class	Intern {
	public:
		Intern();
		Intern(Intern const &arg);
		~Intern();
		Intern &operator=(Intern const &arg);
		Form *makeForm(std::string const nameForm, std::string const targetForm);
		class InternCannotCreateForm : public std::exception{
				public :
					virtual const char* what() const throw();
			};
};

#endif

