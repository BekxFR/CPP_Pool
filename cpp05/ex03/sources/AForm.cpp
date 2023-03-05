/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chillion <chillion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 11:14:22 by chillion          #+#    #+#             */
/*   Updated: 2023/03/01 11:14:23 by chillion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("Undefined"), _signGrade(160), _execGrade(160)
{
	this->_signed = false;
	std::cout << "AForm Default Constructor called" << std::endl;
}

AForm::AForm(std::string const name, unsigned int const signGrade, unsigned int const execGrade) : _name(name), _signGrade(testGrade(signGrade)), _execGrade(testGrade(execGrade))
{
	this->_signed = false;
	std::cout << "AForm Overload Constructor called" << std::endl;
}

AForm::AForm(AForm const &obj) : _name(obj.getName()), _signGrade(obj.getSignGrade()), _execGrade(obj.getExecGrade())
{
	this->_signed = false;
	*this = obj;
}
AForm::~AForm()
{
	std::cout << "AForm Destructor called" << std::endl;
}
AForm &AForm::operator=(AForm const &obj)
{
	std::cout << "AForm Copy assignment operator called" << std::endl;
	(void)obj;
	return *this;
}

std::string AForm::getName() const
{
	return (this->_name);
}

int AForm::getSignGrade() const
{
	return (this->_signGrade);
}

int AForm::getExecGrade() const
{
	return (this->_execGrade);
}

bool AForm::getSigned() const
{
	return (this->_signed);
}

int	AForm::testGrade(unsigned int grade) const
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

void	AForm::formChecker(Bureaucrat &bureaucrat)
{
	if (this->getSigned() == true)
	{
		throw (AForm::SignStatusException());
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

void	AForm::beSigned(Bureaucrat &bureaucrat)
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
	// catch (AForm::SignStatusException &e)
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

void AForm::execChecker(const Bureaucrat& obj) const
{
	if (this->getSigned() == false)
	{
		throw (NoSignStatusException());
	}
	if (this->getSignGrade() == 0 || this->getExecGrade() == 0)
	{
		throw (GradeUnvailableException());
	}
	else if (obj.getGrade() > this->getExecGrade())
	{
		throw (Bureaucrat::GradeTooLowException());
	}
}

void	AForm::beExec(Bureaucrat &bureaucrat)
{
	try
	{
		this->execChecker(bureaucrat);
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
	catch (NoSignStatusException &e)
	{
		std::cerr << bureaucrat.getName() << " couldn’t execut " << this->getName() << " because ";
		std::cerr << e.what() << std::endl;
		return ;
	}
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Form grade is not correct ! He is too high !");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Form grade is not correct ! He is too low !"); 
}

const char *AForm::GradeUnvailableException::what() const throw()
{
	return ("Form grade is unvailable and he can't be used or signed!"); 
}

const char *AForm::SignStatusException::what() const throw()
{
	return ("Form is already Sign ! Don't need another Sign !"); 
}

const char *AForm::NoSignStatusException::what() const throw()
{
	return ("Form is not sign ! Can't use Form if he's not Sign !"); 
}

std::ostream &operator<<(std::ostream &o,AForm const &rhs)
{
	o << "Form name " << rhs.getName() << " can be sign with grade " << rhs.getSignGrade();
	o << ", execute with grade " << rhs.getExecGrade() << " and sign status is ";
	if (rhs.getSigned() == false)
		o << "unsigned!";
	else
		o << "signed!";
	return o;
}