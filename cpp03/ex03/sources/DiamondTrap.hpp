#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
	private:
	std::string _name;
	DiamondTrap();

	public:
	DiamondTrap(std::string const &name);
	DiamondTrap(DiamondTrap const &obj);
	~DiamondTrap();
	DiamondTrap &operator=(DiamondTrap const &obj);

	void	whoAmI();

	using	ScavTrap::attack;
};

#endif
