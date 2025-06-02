#include "AForm.hpp"
#include <Intern.hpp>
#include <cctype>
#include <cstddef>
#include <iostream>
#include <string>
#include <RobotomyRequestForm.hpp>
#include <ShrubberyCreationForm.hpp>
#include <PresidentialPardonForm.hpp>

Intern::Intern()
{
	return;
}

Intern::~Intern()
{
	return;
}

Intern::Intern(const Intern&)
{
	return;
}

Intern& Intern::operator=(const Intern&)
{
	return *this;
}

unsigned int __hash__(const std::string& word)
{
	int hash = 0;

	for(size_t i = 0 ; i < word.length() ; i++)
	{
		if(std::isalnum(word[i]))
			hash = hash * 31 + std::tolower(word[i]);
	}

	return hash;
}

AForm* Intern::makeForm(const std::string name , const std::string target) const
{
	unsigned int hash = __hash__(name);
	AForm *form = NULL;

	switch (hash) {
		case 0x766865BE :
			form = new RobotomyRequestForm(target);
			break;
		case 0x6595EBB3 :
			form = new ShrubberyCreationForm(target);
			break;
		case 0x0D8D2696 :
			form = new PresidentialPardonForm(target);
			break;
		default:
			form = NULL;
	}

	if(form)
		std::cout << "Intern creates " << form->getName() << std::endl;
	else
		std::cout << "Intern : Form not known" << std::endl;

	return form;
}
