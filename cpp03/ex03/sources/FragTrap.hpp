#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ScavTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	private:

	protected:

	public:
	FragTrap();
	FragTrap(std::string const &name);
	FragTrap(FragTrap const &obj);
	~FragTrap();
	FragTrap &operator=(FragTrap const &obj);

	void highFivesGuys(void);
};

#endif
