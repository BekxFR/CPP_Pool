/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chillion <chillion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 11:05:59 by chillion          #+#    #+#             */
/*   Updated: 2023/03/01 11:12:01 by chillion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "Form.hpp"

class Form;

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

		void	signForm(Form &form);
		void	execForm(Form &form);

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

std::ostream &operator <<(std::ostream &o, const Bureaucrat &rhs);

#endif
