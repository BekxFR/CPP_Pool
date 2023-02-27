
#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	private:
	int	_guardStatus;

	public:
	ScavTrap();
	ScavTrap(std::string const &name);
	ScavTrap(ScavTrap const &obj);
	~ScavTrap();
	ScavTrap &operator=(ScavTrap const &obj);

	void	guardGate();

	void	attack(const std::string &target);
};

#endif
