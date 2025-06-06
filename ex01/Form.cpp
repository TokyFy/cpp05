#include <Form.hpp>

const char* Form::GradeTooHighException::what() const throw()
{
	return "[ Form ] : GradeTooHighException thrown";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "[ Form ] : GradeTooLowException thrown";
}

Form::Form()
	:name("Contract") , isSigned(false) , signGrade(MIN_GRADE) , execGrade(MIN_GRADE)
{
	return;
}

Form::~Form()
{
	return;
}

Form::Form(const Form& form)
	:name(form.name) , isSigned(form.isSigned) , signGrade(form.signGrade) , execGrade(form.execGrade)
{
	return;
}

Form& Form::operator=(const Form& form)
{
	(void)(form);
	return *this;
}

Form::Form(const std::string name , int sign , int exec)
	:name(name) , isSigned(false) , signGrade(sign) , execGrade(exec)
{
	if(signGrade < MAX_GRADE || execGrade < MAX_GRADE)
		throw Form::GradeTooHighException();

	if(signGrade > MIN_GRADE || execGrade > MIN_GRADE)
		throw Form::GradeTooLowException();

	return;
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
	if(signGrade < bureaucrat.getGrade())
		throw Form::GradeTooLowException();

	if(isSigned)
		throw std::runtime_error(name + ", already signed");

	isSigned = true;
}

const std::string Form::getName() const
{
	return name;
}

bool Form::getIsSigned() const
{
	return isSigned;
}

int Form::getExecGrade() const
{
	return execGrade;
}

int Form::getSignGrade() const
{
	return signGrade;
}

std::ostream& operator<< (std::ostream& stream , const Form& form)
{
	stream << "Form : " << form.getName()
	<< " , is signed : " << std::boolalpha << form.getIsSigned()
	<< " , Sign grade : " << form.getSignGrade()
	<< " , Exec grade : " << form.getExecGrade();

	return stream;
}
