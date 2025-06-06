#pragma once

#include <Bureaucrat.hpp>
#include <exception>
#include <stdexcept>
#include <string>

class Form
{
	private:
		const	std::string name;
		bool	isSigned;
		const	int signGrade;
		const	int execGrade;

	public:
		Form();
		~Form();
		Form(const Form&);
		Form& operator=(const Form&);
		Form(const std::string name , int sign , int exec);

		void beSigned(const Bureaucrat&);

		const	std::string getName() const;
		bool	getIsSigned() const;
		int		getSignGrade() const;
		int		getExecGrade() const;

	GRADE_EXCEPTION_CLASS(Low);
	GRADE_EXCEPTION_CLASS(High);
};

std::ostream& operator<< (std::ostream& , const Form&);
