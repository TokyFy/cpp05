#include <Bureaucrat.hpp>
#include <Form.hpp>
#include <exception>
#include <iostream>

int main() {

	{
		try
		{
			Form("contract" , 255 , 2);
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
			Form("contract" , 5 , -1);
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
			Form f("contract" , 5 , 5);
			Form contract(f);
			Bureaucrat me("Me" , 5);

			std::cout << me << std::endl;
			me.signForm(contract);
			std::cout << contract << std::endl ;
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

			Form f("contract" , 1 , 1);
			Form contract = f;
			Bureaucrat me("Me" , 2);

			std::cout << me << std::endl;
			std::cout << contract << std::endl ;
			me.signForm(contract);
		}
		catch(std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
}
