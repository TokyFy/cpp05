#pragma once

#include <AForm.hpp>
#include <string>
#include <RobotomyRequestForm.hpp>
#include <ShrubberyCreationForm.hpp>
#include <PresidentialPardonForm.hpp>

class Intern
{
	public:
		Intern();
		~Intern();
		Intern(const Intern&);
		Intern& operator=(const Intern&);

		AForm* makeForm(const std::string , const std::string target) const;
};
