/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chillion <chillion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 11:15:41 by chillion          #+#    #+#             */
/*   Updated: 2023/03/01 11:15:49 by chillion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "ShrubberyCreationForm.hpp"

class Intern
{
	private:

	public:
		Intern();
		Intern(Intern const &obj);
		~Intern();
		Intern &operator=(Intern const &obj);

		AForm	*makeForm(std::string const form, std::string const target);
};

#endif
