#pragma once

#include <AForm.hpp>
#include <iostream>
#include <fstream>

class ShrubberyCreationForm : public AForm
{
	private:
		std::string target;

	public:
		ShrubberyCreationForm();
		~ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm&);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm&);

		void execute(Bureaucrat const & executor) const;
};
