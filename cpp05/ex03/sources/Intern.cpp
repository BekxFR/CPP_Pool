/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chillion <chillion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 11:15:35 by chillion          #+#    #+#             */
/*   Updated: 2023/03/01 11:15:36 by chillion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern Default Constructor called" << std::endl;
}

Intern::Intern(Intern const &obj)
{
	*this = obj;
}

Intern::~Intern()
{
	std::cout << "Intern Destructor called" << std::endl;
}

Intern &Intern::operator=(Intern const &obj)
{
	(void)obj;
	std::cout << "Intern Copy assignment operator called" << std::endl;
	return *this;
}

AForm	*Intern::makeForm(std::string const form, std::string const target)
{
	enum formID {SHRUBERRY, ROBOTOMY, PRESIDENTIAL};
	const std::string	ftab[3] = {"shrubbery creation", "robotomy request", "presidential pardon" };
	int n = 0;
	
	for (; n < 4; n++)
	{
		if (n != 3 && ftab[n] == form)
		{
			break ;
		}
	}
	switch (n)
	{
		case SHRUBERRY :
			std::cout << "Intern creates " << ftab[0] << " form." << std::endl;
			return (new ShrubberyCreationForm(target));
		case ROBOTOMY :
			std::cout << "Intern creates " << ftab[1] << " form." << std::endl;
			return (new RobotomyRequestForm(target));
		case PRESIDENTIAL :
			std::cout << "Intern creates " << ftab[2] << " form." << std::endl;
			return (new PresidentialPardonForm(target));
		default :
		{
			std::cout << "This Form Name don't match with any Form on the current list !" << std::endl;
			return (0);
		}
	}
}