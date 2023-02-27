#include "FragTrap.hpp"

void FragTrap::highFivesGuys(void)
{
	if (this->getHitPoints() == 0)
	{
		std::cout << *this << " is Dead ! "<< std::endl;
		return ;
	}
	std::cout << "Hi ClapTraps it's " << *this << " give me High Fives !" << std::endl;
}

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "FragTrap Default constructor called" << std::endl;
	std::cout << "Name is " << *this << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "with " << (this->getHitPoints()) << " Hit points" << std::endl;
	std::cout << "with " << (this->getEnergyPoints()) << " Energy points" << std::endl;
	std::cout << "with " << (this->getAttackDamage()) << " Attack damage" << std::endl;
}

FragTrap::FragTrap(std::string const &name) : ClapTrap(name)
{
	std::cout << "FragTrap Overload Default constructor called" << std::endl;
	std::cout << "Name is " << *this << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "with " << (this->getHitPoints()) << " Hit points" << std::endl;
	std::cout << "with " << (this->getEnergyPoints()) << " Energy points" << std::endl;
	std::cout << "with " << (this->getAttackDamage()) << " Attack damage" << std::endl;
}

FragTrap::FragTrap(FragTrap const &obj)
{
	std::cout << "FragTrap Copy constructor called" << std::endl;
	*this = obj;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap Destructor called" << std::endl;
}

FragTrap &FragTrap::operator=(FragTrap const &obj)
{
	(void)obj;
	std::cout << "FragTrap Copy assignment operator called" << std::endl;
	this->setName(obj.getName());
	this->setHitPoints(obj.getHitPoints());
	this->setEnergyPoints(obj.getEnergyPoints());
	this->setAttackDamage(obj.getAttackDamage());
	return *this;
}