#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm()
{
	std::cout << "PresidentialPardonForm Default Constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &obj) : AForm(obj)
{
	*this = obj;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm Destructor called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &obj)
{
	std::cout << "PresidentialPardonForm Copy assignment operator called" << std::endl;
	this->_target = obj._target;
	return *this;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	if (target.size() < 1)
		_target = ("Undefined");
	std::cout << "PresidentialPardonForm Overload Constructor called" << std::endl;
}

std::string const	PresidentialPardonForm::getTarget() const
{
	return this->_target;
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
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
	std::cout << this->getTarget() << " was forgiven by President Zaphod Beeblebrox.." << std::endl;
}