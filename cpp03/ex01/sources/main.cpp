#include "ScavTrap.hpp"

int main( void )
{
	ScavTrap scav("Nikita");

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
	scav.setEnergyPoints(10);
	scav.takeDamage(5);
	scav.takeDamage(5);
	scav.takeDamage(5);
	scav.setHitPoints(10);
	scav.takeDamage(5);
	scav.beRepaired(5);
	scav.guardGate();


	ScavTrap scav2(scav);
	scav2.attack("Francis");
	scav2.takeDamage(5);
	scav2.beRepaired(5);
	scav2.guardGate();

	ClapTrap scav3("Marcel");
	scav3 = scav;
	scav3.attack("Arthur");
	scav3.takeDamage(5);
	scav3.beRepaired(5);
	// scav3.guardGate();

	return 0;
}