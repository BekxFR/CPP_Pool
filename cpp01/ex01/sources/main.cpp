#include "Zombie.hpp"

int main()
{
	Zombie *zombiearmy = zombieHorde(10, "Roberto");
	std::cout << "First zombie say Hello"  << std::endl;
	zombiearmy->annonce();
	delete [] zombiearmy;
}