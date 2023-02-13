#include "Zombie.hpp"

Zombie::Zombie() : _name("NULL")
{
	std::cout << "Constructor use for built " << this->_name << std::endl;
}

Zombie::Zombie(std::string name) : _name(name)
{
	std::cout << "Constructor use for built surcharge " << this->_name << std::endl;
}

Zombie::Zombie(Zombie const &autre): _name(autre._name)
{}

Zombie::~Zombie()
{
	std::cout << "Destructor use for delete " << _name << std::endl;
}

Zombie	*newZombie(std::string name)
{
	Zombie *zombie1 = new Zombie(name);
	return (zombie1);
}

void	Zombie::setname(std::string name)
{
	this->_name = name;
}

void	randomChump(std::string name)
{
	Zombie zombie2 = Zombie(name);
	zombie2.annonce();
}

void	Zombie::annonce(void) const
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}