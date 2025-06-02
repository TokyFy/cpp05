#pragma once

#include <string>
#include <Bureaucrat.hpp>

class AForm
{
	private:
		const	std::string name;
		bool	isSigned;
		const	int signGrade;
		const	int execGrade;

	public:
		AForm();
		virtual ~AForm();
		AForm(const AForm&);
		AForm& operator=(const AForm&);
		AForm(const std::string name , int sign , int exec);

		void beSigned(const Bureaucrat&);

		const	std::string getName() const;
		bool	getIsSigned() const;
		int		getSignGrade() const;
		int		getExecGrade() const;

		void check(Bureaucrat const & executor) const;
		virtual void execute(Bureaucrat const & executor) const =0;

	GRADE_EXCEPTION_CLASS(Low);
	GRADE_EXCEPTION_CLASS(High);
};

std::ostream& operator<< (std::ostream& , const AForm&);
