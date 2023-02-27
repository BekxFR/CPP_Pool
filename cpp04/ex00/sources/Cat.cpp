#include "Cat.hpp"

Cat::Cat() : Animal()
{
	this->setType("Cat");
	std::cout << "Cat Default Constructor called" << std::endl;
}
Cat::Cat(Cat const &obj)
{
	*this = obj;
}
Cat::~Cat()
{
	std::cout << "Cat Destructor called" << std::endl;
}
Cat &Cat::operator=(Cat const &obj)
{
	std::cout << "Cat Copy assignment operator called" << std::endl;
	this->setType(obj.getType());
	return *this;
}

void	Cat::makeSound(void) const
{
	std::cout << "I am a " << this->getType() << " Meowwwwwwwwww ! " << std::endl;
}
