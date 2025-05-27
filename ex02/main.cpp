#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <Bureaucrat.hpp>
#include <AForm.hpp>
#include <exception>
#include <iostream>
#include <sys/types.h>


int main() {
	{
		try
		{
			Bureaucrat foo("Me" , 138);
			ShrubberyCreationForm form("ft");

			foo.signForm(form);
			foo.executeForm(form);

			foo.upGrade();
			foo.executeForm(form);
		}
		catch(std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << std::endl;

	{
			try
			{
				Bureaucrat foo("Me" , 45);
				RobotomyRequestForm form("ft");

				foo.signForm(form);
				foo.executeForm(form);
				foo.executeForm(form);
				foo.executeForm(form);
				foo.executeForm(form);
				foo.executeForm(form);
				foo.executeForm(form);
				foo.executeForm(form);
				foo.executeForm(form);
				foo.executeForm(form);
			}
			catch(std::exception &e)
			{
				std::cout << e.what() << std::endl;
			}
	}

	std::cout << std::endl;

	{
		try
		{
			Bureaucrat foo("Me" , 6);
			PresidentialPardonForm form("ft");

			foo.signForm(form);
			foo.executeForm(form);
			foo.upGrade();
			std::cout << foo << std::endl;
			foo.executeForm(form);
		}
		catch(std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
}
