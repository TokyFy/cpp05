#include <Bureaucrat.hpp>
#include <AForm.hpp>
#include <exception>
#include <iostream>

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

void Bureaucrat::signForm(AForm& form)
{
	try
	{
		form.beSigned(*this);
		std::cout << name << " signed " << form.getName() << std::endl;
	}
	catch(AForm::GradeTooLowException &e)
	{
		(void)(e);
		std::cout << name << " couldn’t sign " << form.getName() << " because grade too low" << std::endl;
	}
}


void Bureaucrat::executeForm(AForm const & form) const
{
	try
	{
		form.execute(*this);
	}
	catch (AForm::GradeTooLowException &e)
	{
		(void)(e);
		std::cout << name << " couldn't execute " << form.getName() << " , grade too low" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

std::ostream& operator<< (std::ostream& stream , const Bureaucrat& bureaucrat)
{
	stream
		<< bureaucrat.getName()
		<< ", bureaucrat grade "
		<< bureaucrat.getGrade();

	return stream;
}
