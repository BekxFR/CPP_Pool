/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chillion <chillion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 11:15:03 by chillion          #+#    #+#             */
/*   Updated: 2023/03/01 11:15:28 by chillion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <fstream>
#include <cstring>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
	private:
		std::string const _name;
		int _grade;
		Bureaucrat();

	public:
		Bureaucrat(std::string const name, int grade);
		Bureaucrat(Bureaucrat const &obj);
		~Bureaucrat();
		Bureaucrat &operator=(Bureaucrat const &obj);

		const std::string	getName(void) const;
		int					getGrade(void) const;
		int 				testGrade(int grade) const;

		void gradeIncrement();
		void gradeDecrement();

		void	signForm(AForm &AForm);
		void	executeForm(AForm &AForm);

	class GradeTooHighException : public std::exception
	{
		public:
			const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public:
			const char *what() const throw();
	};
};

std::ostream &operator <<(std::ostream &o, const Bureaucrat &bureaucrat);

#endif
