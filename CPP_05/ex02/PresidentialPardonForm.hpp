#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

class PresidentialPardonForm : public Form
{
	private:
		PresidentialPardonForm();

	public:
		~PresidentialPardonForm();
		
		PresidentialPardonForm(PresidentialPardonForm const &orig);
		PresidentialPardonForm& operator=(PresidentialPardonForm const &orig); 
		void execute(Bureaucrat const &executor) const;

		PresidentialPardonForm(std::string const &target);
};

#endif