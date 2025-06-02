#pragma once

#include <exception>
#include <iostream>
#include <string>

#define MAX_GRADE 1
#define MIN_GRADE 150

class AForm;

#define GRADE_EXCEPTION_CLASS(_FORMAT_)								\
	class GradeToo##_FORMAT_##Exception : public std::exception		\
	{																\
		public:														\
			virtual const char* what() const throw();				\
	};																\

class Bureaucrat
{
	private:
		const std::string name;
		int grade;

	public:
		Bureaucrat();
		~Bureaucrat();
		Bureaucrat(const Bureaucrat&);
		Bureaucrat(std::string , int);
		Bureaucrat& operator=(const Bureaucrat&);

		const std::string& getName() const;
		int getGrade() const;

		void upGrade();
		void downGrade();
		void signForm(AForm&);
		void executeForm(AForm const & form) const;

		GRADE_EXCEPTION_CLASS(Low);
		GRADE_EXCEPTION_CLASS(High);
};

std::ostream& operator<< (std::ostream& , const Bureaucrat&);
