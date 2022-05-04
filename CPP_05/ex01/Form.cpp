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

Form::Form(std::string const new_name,
					int new_signature,
					int new_done):
				_gradeToSign = new_signature;
				_

