#include "Dog.hpp"

Dog::Dog() : Animal()
{
	this->setType("Dog");
	std::cout << "Dog Default Constructor called" << std::endl;
}
Dog::Dog(Dog const &obj)
{
	*this = obj;
}
Dog::~Dog()
{
	std::cout << "Dog Destructor called" << std::endl;
}
Dog &Dog::operator=(Dog const &obj)
{
	std::cout << "Dog Copy assignment operator called" << std::endl;
	this->setType(obj.getType());
	return *this;
}

void	Dog::makeSound(void) const
{
	std::cout << "I am a " << this->getType() << " Ouaf Ouaf Ouaf ! " << std::endl;
}
