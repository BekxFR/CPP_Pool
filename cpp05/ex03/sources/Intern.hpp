#ifndef INTERN_HPP
#define INTERN_HPP

#include "ShrubberyCreationForm.hpp"

class Intern
{
	private:
	/* data */

	public:
	Intern();
	Intern(Intern const &obj);
	~Intern();
	Intern &operator=(Intern const &obj);

	AForm	*makeForm(std::string const form, std::string const target);
};

#endif
