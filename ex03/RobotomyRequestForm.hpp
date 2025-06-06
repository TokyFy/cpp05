#pragma once

#include <AForm.hpp>
#include <cstdlib>
#include <string>
#include <ctime>

class RobotomyRequestForm : public AForm
{
	private:
		std::string target;

	public:
		RobotomyRequestForm();
		~RobotomyRequestForm();
		RobotomyRequestForm(const std::string target);
		RobotomyRequestForm(const RobotomyRequestForm&);
		RobotomyRequestForm& operator=(const RobotomyRequestForm&);

		void execute(Bureaucrat const & executor) const;
};
