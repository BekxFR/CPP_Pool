#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	this->WrongAnimal::setType("WrongCat");
	std::cout << "WrongCat Default Constructor called" << std::endl;
}
WrongCat::WrongCat(WrongCat const &obj)
{
	*this = obj;
}
WrongCat::~WrongCat()
{
	std::cout << "WrongCat Destructor called" << std::endl;
}
WrongCat &WrongCat::operator=(WrongCat const &obj)
{
	std::cout << "WrongCat Copy assignment operator called" << std::endl;
	this->setType(obj.getType());
	return *this;
}

void	WrongCat::makeSound(void) const
{
	std::cout << "I am a " << this->getType() << " Mouaf Mouaf Mouaf ! " << std::endl;
}
