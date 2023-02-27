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
		// Bureaucrat(std::string const name);
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

	class GradeTooHighException : virtual public std::exception
	{
		public:
			virtual const char *what() const throw();
			// GradeTooHighException() throw();
			// GradeTooHighException(GradeTooHighException const &other) throw();
			// virtual ~GradeTooHighException() throw();
	};

	class GradeTooLowException : virtual public std::exception
	{
		public:
			virtual const char *what() const throw();
			// GradeTooLowException() throw();
			// GradeTooLowException(GradeTooLowException const &other) throw();
			// virtual ~GradeTooLowException() throw();
	};
};

std::ostream &operator <<(std::ostream &o, const Bureaucrat &bureaucrat);

#endif
