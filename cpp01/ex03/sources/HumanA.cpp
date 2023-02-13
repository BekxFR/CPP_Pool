#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon)
{
	std::cout << "HumanA Construct is call for " << this->_name << " with " << this->_weapon.getType() << " weapon " << std::endl;
}

HumanA::~HumanA()
{}

void	HumanA::attack(void)
{
	std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}
