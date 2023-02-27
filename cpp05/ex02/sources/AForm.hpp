#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		std::string const			_name;
		bool						_signed;
		unsigned int const			_signGrade;
		unsigned int const			_execGrade;

	public:
		AForm();
		AForm(std::string const name, unsigned int const signGrade, unsigned int const execGrade);
		AForm(AForm const &obj);
		virtual ~AForm();
		AForm &operator=(AForm const &obj);

		std::string	getName() const;
		int			getSignGrade() const;
		int			getExecGrade() const;
		bool		getSigned() const;

		void	beSigned(Bureaucrat &bureaucrat);
		void	beExec(Bureaucrat &bureaucrat);

		int		testGrade(unsigned int grade) const;
		void	formChecker(Bureaucrat &bureaucrat);
		void	execChecker(const Bureaucrat& obj) const;

		virtual void		execute(Bureaucrat const &executor) const = 0;

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
	class NoSignStatusException : virtual public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
};

std::ostream &operator <<(std::ostream &o, AForm const &rhs);

#endif
