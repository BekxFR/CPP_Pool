#include "ScavTrap.hpp"

void	ScavTrap::guardGate()
{
	if (this->_guardStatus == 0)
	{
	if (this->getHitPoints() == 0)
	{
		std::cout << *this << " is Dead ! "<< std::endl;
		return ;
	}
		std::cout << *this  << " active Gate Keeper mode !" << std::endl;
		this->_guardStatus = 1;
	}
	else
	{
		std::cout << *this  << " disable Gate Keeper mode !" << std::endl;
		this->_guardStatus = 0;
	}
}

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "ScavTrap Default constructor called" << std::endl;
	std::cout << "Name is " << *this << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	this->_guardStatus = 0;
	std::cout << "with " << (this->getHitPoints()) << " Hit points" << std::endl;
	std::cout << "with " << (this->getEnergyPoints()) << " Energy points" << std::endl;
	std::cout << "with " << (this->getAttackDamage()) << " Attack damage" << std::endl;
}

ScavTrap::ScavTrap(std::string const &name) : ClapTrap(name)
{
	std::cout << "ScavTrap Overload Default constructor called" << std::endl;
	std::cout << "Name is " << *this << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	this->_guardStatus = 0;
	std::cout << "with " << (this->getHitPoints()) << " Hit points" << std::endl;
	std::cout << "with " << (this->getEnergyPoints()) << " Energy points" << std::endl;
	std::cout << "with " << (this->getAttackDamage()) << " Attack damage" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &obj)
{
	std::cout << "ScavTrap Copy constructor called" << std::endl;
	*this = obj;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &obj)
{
	(void)obj;
	std::cout << "ScavTrap Copy assignment operator called" << std::endl;
	this->setName(obj.getName());
	this->setHitPoints(obj.getHitPoints());
	this->setEnergyPoints(obj.getEnergyPoints());
	this->setAttackDamage(obj.getAttackDamage());
	this->_guardStatus = 0;
	return *this;
}

void	ScavTrap::attack(const std::string &target)
{
	if (this->getHitPoints() == 0)
	{
		std::cout << *this << " is Dead ! "<< std::endl;
		return ;
	}
	if (this->getEnergyPoints() == 0)
	{
		std::cout << *this << " dont have enough energy !" << std::endl;
		return ;
	}
	if (target.size() < 1)
		std::cout << "Furious ScavTrap " << *this << " attacks Undefined ClapTrap causing " << this->getAttackDamage() << " points of damage !" << std::endl;
	else
		std::cout << "Furious ScavTrap " << *this << " attacks " << target << " causing " << this->getAttackDamage() << " points of damage !" << std::endl;
	this->setEnergyPoints(this->getEnergyPoints() - 1);
}
