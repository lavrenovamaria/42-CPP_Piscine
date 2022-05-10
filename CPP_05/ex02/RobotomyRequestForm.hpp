#ifndef ROBOTOMYREQUESTFORM_H
# define ROBOTOMYREQUESTFORM_H

# include <iostream>
# include <cstdlib>
# include "Bureaucrat.hpp"
# include "Form.hpp"


class RobotomyRequestForm : public Form
{

public:
	RobotomyRequestForm();
	~RobotomyRequestForm();
	RobotomyRequestForm(RobotomyRequestForm const &orig);
	RobotomyRequestForm& operator=(RobotomyRequestForm const &orig);

	void execute(Bureaucrat const &executor) const;
	RobotomyRequestForm(std::string const &target);
};

#endif
