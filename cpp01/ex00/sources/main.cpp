#include "Zombie.hpp"

int main()
{
	Zombie *zombie1 = newZombie("Roberto");
	zombie1->annonce();

	randomChump("Carlos");
	delete zombie1;
}