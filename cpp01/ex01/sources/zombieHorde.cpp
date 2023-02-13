#include "Zombie.hpp"
#include <sstream>

Zombie* zombieHorde(int N, std::string name)
{
	Zombie *horde = new Zombie[N];
	std::string new_name;

	for (int i = 0; i < N; i++)
	{
		std::ostringstream oss;
		oss << name << (i + 1);
		new_name = oss.str();
		horde[i].setname(new_name);
		new_name.erase();
		horde[i].annonce();
	}
	return (&(horde[0]));
}