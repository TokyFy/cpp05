#include "AForm.hpp"
#include <Intern.hpp>
#include <iostream>

unsigned int __hash__(const std::string& word);

int main() {

    if(__h 


	Intern me;

	AForm *rb_form = me.makeForm("robotomy request", "people");
	std::cout << *rb_form << std::endl << std::endl;
	delete rb_form;


	AForm *sc_form = me.makeForm("Shrubbery Creation   ", "people");
	std::cout << *sc_form << std::endl << std::endl;
	delete sc_form;

	AForm *pp_form = me.makeForm("presiDential Pardon", "people");
	std::cout << *pp_form << std::endl << std::endl;
	delete pp_form;


	me.makeForm("", "people");
	me.makeForm("foo", "people");

	return 0;
}
