#include "FragTrap.hpp"

int main( void )
{
	FragTrap scav("Nikita");

	scav.attack("Francis");
	scav.attack("Francis");
	scav.attack("Francis");
	scav.attack("Francis");
	scav.attack("Francis");
	scav.attack("Francis");
	scav.attack("Francis");
	scav.attack("Francis");
	scav.attack("Francis");
	scav.attack("Francis");
	scav.attack("Francis");
	scav.attack("Francis");
	while(scav.getEnergyPoints() > 0)
		scav.attack("Maurice");
	scav.attack("Phill");
	scav.setEnergyPoints(2);
	scav.takeDamage(5);
	scav.takeDamage(5);
	scav.takeDamage(5);
	scav.setHitPoints(10);
	scav.takeDamage(5);
	scav.beRepaired(5);
	scav.highFivesGuys();
	// scav.guardGate();


	FragTrap scav2(scav);
	scav2.attack("Francis");
	scav2.takeDamage(5);
	scav2.beRepaired(5);
	scav2.highFivesGuys();

	ScavTrap scav3("Marcel");
	scav3.attack("Arthur");
	scav3.takeDamage(5);
	scav3.beRepaired(5);
	scav3.guardGate();
	// scav3.highFivesGuys();

	ClapTrap scav4("Jean-Yves");
	// scav4.guardGate();
	// scav4.highFivesGuys();
	scav4 = scav;
	scav4.attack("Arthur");
	scav4.takeDamage(5);
	scav4.beRepaired(5);
	// scav4.highFivesGuys();


	return 0;
}