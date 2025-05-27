#include <RobotomyRequestForm.hpp>
#include <AForm.hpp>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

RobotomyRequestForm::RobotomyRequestForm()
	:AForm("RobotomyRequestForm" , 72 , 45) , target("Human")
{
	return;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	return;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target)
	:AForm("RobotomyRequestForm" , 72 , 45) , target(target)
{
	return;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& form)
	:AForm("RobotomyRequestForm" , 72 , 45) , target(form.target)
{
	return;
}


RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& form)
{
	target = form.target;
	return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	this->check(executor);

	static int n = 0;

	if(n++ == 0)
		srand(time(0));

	if(rand() % 2 == 0)
	{
		std::cout << "\a" << target << " has been robotomized successfully" << std::endl;
	}
	else
	{
		std::cout << "robotomy of " << target <<  " failed" << std::endl;
	}

	return;
}
