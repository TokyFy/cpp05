#include <Bureaucrat.hpp>
#include <AForm.hpp>
#include <stdexcept>

const char* AForm::GradeTooHighException::what() const throw()
{
	return "[ AForm ] : GradeTooHighException thrown";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "[ AForm ] : GradeTooLowException thrown";
}

AForm::AForm()
	:name("Contract") , isSigned(false) , signGrade(MIN_GRADE) , execGrade(MIN_GRADE)
{
	return;
}

AForm::~AForm()
{
	return;
}

AForm::AForm(const AForm& form)
	:name(form.name) , isSigned(form.isSigned) , signGrade(form.signGrade) , execGrade(form.execGrade)
{
	return;
}

AForm& AForm::operator=(const AForm& form)
{
	(void)(form);
	return *this;
}

AForm::AForm(const std::string name , int sign , int exec)
	:name(name) , isSigned(false) , signGrade(sign) , execGrade(exec)
{
	if(signGrade < MAX_GRADE || execGrade < MAX_GRADE)
		throw AForm::GradeTooHighException();

	if(signGrade > MIN_GRADE || execGrade > MIN_GRADE)
		throw AForm::GradeTooLowException();

	return;
}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if(signGrade < bureaucrat.getGrade())
		throw AForm::GradeTooLowException();

	if(isSigned)
		throw std::runtime_error(name + ", already signed");

	isSigned = true;
}

const std::string AForm::getName() const
{
	return name;
}

bool AForm::getIsSigned() const
{
	return isSigned;
}

int AForm::getExecGrade() const
{
	return execGrade;
}

int AForm::getSignGrade() const
{
	return signGrade;
}

std::ostream& operator<< (std::ostream& stream , const AForm& form)
{
	stream << "AForm : " << form.getName()
	<< " , is signed : " << std::boolalpha << form.getIsSigned()
	<< " , Sign grade : " << form.getSignGrade()
	<< " , Exec grade : " << form.getExecGrade();

	return stream;
}

void AForm::check(Bureaucrat const & executor) const
{
	if(!this->getIsSigned())
		throw std::runtime_error(executor.getName() + " can't exec " + name + ", it's not signed yet");

	if	(
		this->getExecGrade() < executor.getGrade() ||
		this->getSignGrade() < executor.getGrade()
		)
			throw AForm::GradeTooLowException();
};
