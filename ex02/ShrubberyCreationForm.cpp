#include <ShrubberyCreationForm.hpp>
#include <AForm.hpp>
#include <iostream>
#include <fstream>
#include <string>

ShrubberyCreationForm::ShrubberyCreationForm()
	:AForm("ShrubberyCreationForm" , 145 , 137) , target("Shrubbery")
{
	return;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	return;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target)
	:AForm("ShrubberyCreationForm" , 145 , 137) , target(target)
{
	return;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& form)
	:AForm("ShrubberyCreationForm" , 145 , 137) , target(form.target)
{
	return;
}


ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& form)
{
	target = form.target;
	return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	this->check(executor);

	std::ofstream file((target + "_shrubbery").c_str());

	if(!file.is_open())
		std::cout << "Failed to open " << target << "_shrubbery" << std::endl;

	file << "                " << std::endl;
	file << "                " << std::endl;
	file << "    *  ~  #     " << std::endl;
	file << "     \\_|_/ %   " << std::endl;
	file << "       |__/     " << std::endl;
	file << "_.__*__|___,___," << std::endl;
	file << "                " << std::endl;

	file.close();

	std::cout << this->getName() << " excecuted succefully" << std::endl;
	return;
}
