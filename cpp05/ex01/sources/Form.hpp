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

	class GradeTooHighException : virtual public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
	class GradeTooLowException : virtual public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
	class GradeUnvailableException : virtual public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
	class SignStatusException : virtual public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
};

std::ostream &operator <<(std::ostream &o, Form const &rhs);

#endif
