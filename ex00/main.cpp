#include <exception>
#include <iostream>
#include <Bureaucrat.hpp>

int main()
{
	{
		try
		{
			Bureaucrat foo("foo" , -1);
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
			Bureaucrat foo("foo" , 256);
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
			Bureaucrat bar("bar" , 2);
			Bureaucrat foo = bar;
			std::cout << foo << std::endl;
			foo.upGrade();
			std::cout << foo << std::endl;
			foo.upGrade();
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << std::endl;

	{
		try
		{
			Bureaucrat bar("foo" , 149);
			Bureaucrat foo(bar);
			std::cout << foo << std::endl;
			foo.downGrade();
			std::cout << foo << std::endl;
			foo.downGrade();
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
}
