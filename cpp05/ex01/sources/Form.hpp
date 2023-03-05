/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chillion <chillion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 11:06:11 by chillion          #+#    #+#             */
/*   Updated: 2023/03/01 11:23:36 by chillion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		std::string const			_name;
		bool						_signed;
		unsigned int const			_signGrade;
		unsigned int const			_execGrade;
		Form();

	public:
		Form(std::string const name, unsigned int const signGrade, unsigned int const execGrade);
		Form(Form const &obj);
		~Form();
		Form &operator=(Form const &obj);

		std::string	getName() const;
		int			getSignGrade() const;
		int			getExecGrade() const;
		bool		getSigned() const;

		void	beSigned(Bureaucrat &bureaucrat);
		void	beExec(Bureaucrat &bureaucrat);

		int		testGrade(unsigned int grade) const;
		void	formChecker(Bureaucrat &bureaucrat);
		void	execChecker(const Bureaucrat& obj) const;

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
	class GradeUnvailableException : public std::exception
	{
		public:
			const char *what() const throw();
	};
	class SignStatusException : public std::exception
	{
		public:
			const char *what() const throw();
	};
	class NoSignStatusException : public std::exception
	{
		public:
			const char *what() const throw();
	};
};

std::ostream &operator <<(std::ostream &o, Form const &rhs);

#endif
