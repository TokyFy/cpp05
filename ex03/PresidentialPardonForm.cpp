#include <PresidentialPardonForm.hpp>

PresidentialPardonForm::PresidentialPardonForm()
	:AForm("PresidentialPardonForm" , 25 , 5) , target("Shrubbery")
{
	return;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	return;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target)
	:AForm("PresidentialPardonForm" , 25 , 5) , target(target)
{
	return;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& form)
	:AForm("PresidentialPardonForm" , 25 , 5) , target(form.target)
{
	return;
}


PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& form)
{
	target = form.target;
	return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	this->check(executor);

	std::cout << target << " has been pardoned by Zaphod Beeblebrox" << std::endl;

	return;
}
