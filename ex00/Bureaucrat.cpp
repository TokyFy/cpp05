#include <Bureaucrat.hpp>

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "[ Bureaucrat ] : GradeTooHighException thrown";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "[ Bureaucrat ] : GradeTooLowException thrown";
}


Bureaucrat::Bureaucrat()
	:name("_Bureaucrat_") , grade(150)
{
	return;
}

Bureaucrat::Bureaucrat(std::string name , int n)
	:name(name)
{
	if(n < MAX_GRADE)
		throw Bureaucrat::GradeTooHighException();

	if(n > MIN_GRADE)
		throw Bureaucrat::GradeTooLowException();

	grade = n;
}

Bureaucrat::~Bureaucrat()
{
	return;
}

Bureaucrat::Bureaucrat(const Bureaucrat& bureaucrat)
	:name(bureaucrat.name) , grade(bureaucrat.grade)
{
	return;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& bureaucrat)
{
	if(this == &bureaucrat)
		return *this;

	grade = bureaucrat.grade;

	return *this;
}

const std::string& Bureaucrat::getName() const
{
	return name;
}

int Bureaucrat::getGrade() const
{
	return grade;
}

void Bureaucrat::upGrade()
{
	int n = grade - 1;

	if(n < MAX_GRADE)
		throw Bureaucrat::GradeTooHighException();

	grade = n;
}

void Bureaucrat::downGrade()
{
	int n = grade + 1;

	if(n > MIN_GRADE)
		throw Bureaucrat::GradeTooLowException();

	grade = n;
}

std::ostream& operator<< (std::ostream& stream , const Bureaucrat& bureaucrat)
{
	stream
		<< bureaucrat.getName()
		<< ", bureaucrat grade "
		<< bureaucrat.getGrade();

	return stream;
}
