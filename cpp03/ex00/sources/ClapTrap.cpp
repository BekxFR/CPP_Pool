#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Default constructor called" << std::endl;
	this->setName("Undefined");
}

ClapTrap::ClapTrap(std::string const &name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Overload Default constructor called" << std::endl;
	if (name.size() < 1)
		this->setName("Undefined");
	std::cout << "Name is " << *this << std::endl;
	std::cout << "with " << (this->getHitPoints()) << " Hit points" << std::endl;
	std::cout << "with " << (this->getEnergyPoints()) << " Energy points" << std::endl;
	std::cout << "with " << (this->getAttackDamage()) << " Attack damage" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &autre)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = autre;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
}

const std::string &ClapTrap::getName() const
{
	return (this->_name);
}

int	ClapTrap::getHitPoints() const
{
	return (this->_hitPoints);
}

int	ClapTrap::getEnergyPoints() const
{
	return (this->_energyPoints);
}

int	ClapTrap::getAttackDamage() const
{
	return (this->_attackDamage);
}

ClapTrap	&ClapTrap::operator=(ClapTrap const &autre)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->setName(autre.getName());
	this->setHitPoints(autre.getHitPoints());
	this->setEnergyPoints(autre.getEnergyPoints());
	this->setAttackDamage(autre.getAttackDamage());
	return *this;
}

std::ostream &operator<<(std::ostream &o, ClapTrap const &rhs)
{
	o << rhs.getName();
	return o;
}

void ClapTrap::setName(std::string const &name)
{
	this->_name = name;
}

void	ClapTrap::setHitPoints(int const hitPoints)
{
	if (hitPoints >= 0)
		this->_hitPoints = hitPoints;
	else
		this->_hitPoints = 0;
}

void	ClapTrap::setEnergyPoints(int const energyPoints)
{
	if (energyPoints >= 0)
		this->_energyPoints = energyPoints;
	else
		this->_energyPoints = 0;
}

void	ClapTrap::setAttackDamage(int const attackDamage)
{
	if (attackDamage >= 0)
		this->_attackDamage = attackDamage;
	else
		this->_attackDamage = 0;
}

void	ClapTrap::attack(const std::string &target)
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
		std::cout << "ClapTrap " << *this << " attacks Undefined ClapTrap causing " << this->getAttackDamage() << " points of damage !" << std::endl;
	else
		std::cout << "ClapTrap " << *this << " attacks " << target << " causing " << this->getAttackDamage() << " points of damage !" << std::endl;
	this->setEnergyPoints(this->getEnergyPoints() - 1);
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->getHitPoints() == 0)
	{
		std::cout << *this << " is already Dead ! Stop the relentlessness pls ! "<< std::endl;
		return ;
	}
	this->setHitPoints(this->getHitPoints() - amount);
	std::cout << *this << " take " << amount << " damage and he have actually " << this->getHitPoints() << " hit points !" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->getHitPoints() == 0)
	{
		std::cout << *this << " is Dead ! " << std::endl;
		return ;
	}
	if (this->getEnergyPoints() == 0)
	{
		std::cout << *this << " dont have enough energy !" << std::endl;
		return ;
	}
	this->setHitPoints(this->getHitPoints() + amount);
	std::cout << *this << " be repared to " << amount << " hit points and he have actually " << this->getHitPoints() << " hit points !" << std::endl;
	this->setEnergyPoints(this->getEnergyPoints() - 1);
}

