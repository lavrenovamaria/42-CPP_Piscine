#ifndef SHRUBBERYCREATIONFORM_H
# define SHRUBBERYCREATIONFORM_H

#include <iostream>
#include <exception> 
#include "Bureaucrat.hpp"
#include <fstream> // для чтения/записи данных из/в файл
#include "Form.hpp"

class ShrubberyCreationForm : public Form
{
	private:
		ShrubberyCreationForm();

	public:
		~ShrubberyCreationForm();
		
		ShrubberyCreationForm(ShrubberyCreationForm const &orig);
		ShrubberyCreationForm& operator=(ShrubberyCreationForm const &orig); 
		void execute(Bureaucrat const &executor) const;
		ShrubberyCreationForm(std::string const &target);

};

#endif