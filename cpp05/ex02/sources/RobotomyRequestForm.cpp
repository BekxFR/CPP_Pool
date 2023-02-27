#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm Default Constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &obj) : AForm(obj)
{
	*this = obj;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm Destructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &obj)
{
	std::cout << "RobotomyRequestForm Copy assignment operator called" << std::endl;
	this->_target = obj._target;
	return *this;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	if (target.size() < 1)
		_target = ("Undefined");
	std::cout << "RobotomyRequestForm Overload Constructor called" << std::endl;
}

std::string const	RobotomyRequestForm::getTarget() const
{
	return this->_target;
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	try
	{
		this->execChecker(executor);
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << executor.getName() << " couldn’t execut " << this->getName() << " because ";
		std::cerr << e.what() << std::endl;
		return ;
	}
	catch (GradeUnvailableException &e)
	{
		std::cerr << executor.getName() << " couldn’t execut " << this->getName() << " because ";
		std::cerr << e.what() << std::endl;
		return ;
	}
	catch (NoSignStatusException &e)
	{
		std::cerr << executor.getName() << " couldn’t execut " << this->getName() << " because ";
		std::cerr << e.what() << std::endl;
		return ;
	}
	bool trueFalse = ((rand() % 6) < 3);
	// std::srand(time(0));
	std::cout << "Bzrrr Bzrrrr Bzrrrrrr Bzrr Bzrrr ";
	std::cout << "Bzrrr Bzrr Bzrrr Bzrrr Bzrrrrr" << std::endl;
	std::cout << "Bzrrrr Bzrrrrr Bzrrr Bzrr Bzrrrr ";
	// if ((std::rand() % 2) == 0)
	if (trueFalse == true)
		std::cout << this->getTarget() << " robotomiz fail !" << std::endl;
	else 
		std::cout << this->getTarget() << " was robotomized succesfully !" << std::endl;
}