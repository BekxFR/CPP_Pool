#include "Animal.hpp"

Animal::Animal()
{
	this->setType("Undefined");
	std::cout << "Animal Default Constructor called" << std::endl;
}
Animal::Animal(Animal const &obj)
{
	*this = obj;
}
Animal::~Animal()
{
	std::cout << "Animal Destructor called" << std::endl;
}
Animal &Animal::operator=(Animal const &obj)
{
	std::cout << "Animal Copy assignment operator called" << std::endl;
	this->setType(obj.getType());
	return *this;
}
Animal::Animal(std::string const &type)
{
	if (type.size() < 1)
		this->setType("Undefined");
	else
		this->setType(type);
	std::cout << "Animal Overload Constructor called" << std::endl;
}

void	Animal::setType(std::string const &type)
{
	this->_type = type;
}

const std::string	&Animal::getType() const
{
	return this->_type;
}

void	Animal::makeSound(void) const
{
	std::cout << "I am a " << _type << " my sound is like *#__*_*__#*" << std::endl;
}
