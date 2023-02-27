
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Unknow Name"), _grade(150)
{
	std::cout << "Bureaucrat Default Constructor called" << std::endl;
}

// Bureaucrat::Bureaucrat(std::string const name) : _name(name), _grade(150)
// {
// 	std::cout << "Bureaucrat Overload Constructor called" << std::endl;
// }

Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name)
{
	std::cout << "Bureaucrat Overload Constructor called" << std::endl;
	this->_grade = grade;
	this->_grade = testGrade(grade);
	return ;
}

int	Bureaucrat::testGrade(int grade) const
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
		return (this->getGrade() == 1) ? 1 : 150;
	}
	catch (GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
		return (150);
	}
	return (grade);
}

Bureaucrat::Bureaucrat(Bureaucrat const &obj) : _name(obj.getName())
{
	*this = obj;
}
Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat Destructor called" << std::endl;
}
Bureaucrat &Bureaucrat::operator=(Bureaucrat const &obj)
{
	std::cout << "Bureaucrat Copy assignment operator called" << std::endl;
	this->_grade = obj.getGrade();
	return *this;
}

int	Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

const std::string	Bureaucrat::getName(void) const
{
	return (this->_name);
}

void Bureaucrat::gradeIncrement()
{
	this->_grade = testGrade(this->_grade - 1);
	return ;
}

void Bureaucrat::gradeDecrement()
{
	this->_grade = testGrade(this->_grade + 1);
	return ;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Bureaucrat grade is not correct ! He can't be higher to 1 !");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Bureaucrat grade is not correct ! He can't be lower to 150 !"); 
}

std::ostream &operator<<(std::ostream &o, Bureaucrat const &rhs)
{
	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << ".";
	return o;
}
