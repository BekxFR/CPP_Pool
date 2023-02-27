#include "ClapTrap.hpp"

int main( void )
{
	ClapTrap clap("Hubert");

	clap.attack("Francis");
	clap.attack("Francis");
	clap.attack("Francis");
	clap.attack("Francis");
	clap.attack("Francis");
	clap.attack("Francis");
	clap.attack("Francis");
	clap.attack("Francis");
	clap.attack("Francis");
	clap.attack("Francis");
	clap.attack("Francis");
	clap.attack("Francis");
	clap.setEnergyPoints(10);
	clap.takeDamage(5);
	clap.takeDamage(5);
	clap.takeDamage(5);
	clap.setHitPoints(10);
	clap.takeDamage(5);
	clap.beRepaired(5);


	ClapTrap clap1("");

	clap1.attack("Francis");
	clap1.attack("");
	clap1.attack("Francis");
	clap1.attack("Francis");
	clap1.attack("Francis");
	clap1.attack("Francis");
	clap1.setAttackDamage(10);
	clap1.attack("Francis");
	clap1.attack("Francis");
	clap1.attack("Francis");
	clap1.attack("Francis");
	clap1.attack("Francis");
	clap1.attack("Francis");
	clap1.attack("Francis");
	clap1.beRepaired(5);
	clap1.setEnergyPoints(10);
	clap1.takeDamage(12);
	clap1.takeDamage(5);
	clap1.beRepaired(5);
	clap1.takeDamage(5);
	clap1.setHitPoints(10);
	clap1.takeDamage(5);
	clap1.beRepaired(5);


	ClapTrap clap2("");
	clap2 = clap;
	clap.attack("Francis");

	return 0;
}