#include "DiamondTrap.hpp"

int main( void )
{
	DiamondTrap scav("Nikita");

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
	scav.highFivesGuys();
	scav.whoAmI();
	scav.guardGate();
	scav.guardGate();

	DiamondTrap scav2(scav);
	scav.attack("Francis");
	scav.whoAmI();
	scav.guardGate();

	std::cout << "###############################################" << std::endl;
/* 
	ScavTrap scav1("Francis");
	scav1.attack("Nikita");
	scav1.attack("Nikita");
	scav1.attack("Nikita");
	scav1.attack("Nikita");
	scav1.attack("Nikita");
	scav1.attack("Nikita");
	scav1.attack("Nikita");
	scav1.attack("Nikita");
	scav1.attack("Nikita");
	scav1.attack("Nikita");
	scav1.attack("Nikita");
	scav1.attack("Nikita");
	while(scav1.getEnergyPoints() > 0)
		scav1.attack("Maurice");
	scav1.attack("Phill");
	scav1.setEnergyPoints(10);
	scav1.takeDamage(5);
	scav1.takeDamage(5);
	scav1.takeDamage(5);
	scav1.setHitPoints(10);
	scav1.takeDamage(5);
	scav1.beRepaired(5);
	scav1.guardGate();
	scav1.guardGate();
	// scav1.highFivesGuys();
	// scav1.whoAmI();
 */
	std::cout << "###############################################" << std::endl;
/* 
	FragTrap scav3;
	scav3 = scav;
	scav3.attack("Francis");
	scav3.takeDamage(5);
	scav3.beRepaired(5);
	scav3.highFivesGuys();
	// scav3.whoAmI();
	// scav3.guardGate();
 */
	std::cout << "###############################################" << std::endl;
/* 
	ScavTrap scav5("Yves-Jean");
	scav5 = scav;
	scav5.attack("Arthur");
	scav5.takeDamage(5);
	scav5.beRepaired(5);
	// scav5.whoAmI();
	scav5.guardGate();
	// scav5.highFivesGuys();
 */
	std::cout << "###############################################" << std::endl;
/* 
	ClapTrap scav6("Jean-Yves");
	scav6 = scav;
	scav6.attack("Arthur");
	scav6.takeDamage(5);
	scav6.beRepaired(5);
	// scav5.whoAmI();
	// scav6.guardGate();
	// scav5.highFivesGuys();
 */
	std::cout << "###############################################" << std::endl;
	return 0;
}