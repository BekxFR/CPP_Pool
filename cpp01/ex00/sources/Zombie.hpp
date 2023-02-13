#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie
{
	private:
		std::string _name;

	public:
		Zombie();
		Zombie(std::string name);
		Zombie(Zombie const &autre);
		~Zombie();
		void	annonce() const;
};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

#endif
