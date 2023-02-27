#include "Form.hpp"

Form::Form() : _name("Undefined"), _signGrade(160), _execGrade(160)
{
	this->_signed = false;
	std::cout << "Form Default Constructor called" << std::endl;
}

Form::Form(std::string const name, unsigned int const signGrade, unsigned int const execGrade) : _name(name), _signGrade(testGrade(signGrade)), _execGrade(testGrade(execGrade))
{
	this->_signed = false;
	std::cout << "Form Overload Constructor called" << std::endl;
}

Form::Form(Form const &obj) : _name(obj.getName()), _signGrade(obj.getSignGrade()), _execGrade(obj.getExecGrade())
{
	this->_signed = false;
	*this = obj;
}
Form::~Form()
{
	std::cout << "Form Destructor called" << std::endl;
}
Form &Form::operator=(Form const &obj)
{
	std::cout << "Form Copy assignment operator called" << std::endl;
	(void)obj;
	return *this;
}

std::string Form::getName() const
{
	return (this->_name);
}

int Form::getSignGrade() const
{
	return (this->_signGrade);
}

int Form::getExecGrade() const
{
	return (this->_execGrade);
}

bool Form::getSigned() const
{
	return (this->_signed);
}

int	Form::testGrade(unsigned int grade) const
{

	try
	{
		if (grade < 1)
		{
			throw (GradeTooHighException());
		}
		if (grade > 150)
		{
			throw (GradeTooLowException());
		}
	}
	catch (GradeTooHighException &e)
	{
		std::cerr << e.what() << std::endl;
		return (0);
	}
	catch (GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
		return (0);
	}
	return (grade);
}

void	Form::formChecker(Bureaucrat &bureaucrat)
{
	if (this->getSigned() == true)
	{
		throw (Form::SignStatusException());
	}
	if (this->getSignGrade() == 0 || this->getExecGrade() == 0)
	{
		throw (GradeUnvailableException());
	}
	if (bureaucrat.getGrade() > this->getSignGrade())
	{
		throw (Bureaucrat::GradeTooLowException());
	}
}

void	Form::beSigned(Bureaucrat &bureaucrat)
{
	// try
	// {
	// 	this->formChecker(bureaucrat);
	// }
	// catch (Bureaucrat::GradeTooLowException &e)
	// {
	// 	std::cerr << bureaucrat.getName() << " couldn’t sign " << this->getName() << " because ";
	// 	std::cerr << e.what() << std::endl;
	// 	return ;
	// }
	// catch (GradeUnvailableException &e)
	// {
	// 	std::cerr << bureaucrat.getName() << " couldn’t sign " << this->getName() << " because ";
	// 	std::cerr << e.what() << std::endl;
	// 	return ;
	// }
	// catch (Form::SignStatusException &e)
	// {
	// 	std::cerr << bureaucrat.getName() << " couldn’t sign " << this->getName() << " because ";
	// 	std::cerr << e.what() << std::endl;
	// 	return ;
	// }
	if (this->getSigned() == true)
	{
		throw (SignStatusException());
	}
	if (this->getSignGrade() == 0 || this->getExecGrade() == 0)
	{
		throw (GradeUnvailableException());
	}
	if (bureaucrat.getGrade() > this->getSignGrade())
	{
		throw (Bureaucrat::GradeTooLowException());
	}
	this->_signed = true;
}

void	Form::beExec(Bureaucrat &bureaucrat)
{
	try
	{
		this->formChecker(bureaucrat);
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << bureaucrat.getName() << " couldn’t execut " << this->getName() << " because ";
		std::cerr << e.what() << std::endl;
		return ;
	}
	catch (GradeUnvailableException &e)
	{
		std::cerr << bureaucrat.getName() << " couldn’t execut " << this->getName() << " because ";
		std::cerr << e.what() << std::endl;
		return ;
	}
	catch (Form::SignStatusException &e)
	{
		std::cerr << bureaucrat.getName() << " couldn’t execut " << this->getName() << " because ";
		std::cerr << e.what() << std::endl;
		return ;
	}
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Form grade is not correct ! He is too high !");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Form grade is not correct ! He is too low !"); 
}

const char *Form::GradeUnvailableException::what() const throw()
{
	return ("Form grade is unvailable and he can't be used or signed!"); 
}

const char *Form::SignStatusException::what() const throw()
{
	return ("Form is already Sign ! Don't need another Sign !"); 
}

std::ostream &operator<<(std::ostream &o,Form const &rhs)
{
	o << "Form name " << rhs.getName() << " can be sign with grade " << rhs.getSignGrade();
	o << ", execute with grade " << rhs.getExecGrade() << " and sign status is ";
	if (rhs.getSigned() == false)
		o << "unsigned!";
	else
		o << "signed!";
	return o;
}