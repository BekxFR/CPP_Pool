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
	void	setname(std::string name);
};

Zombie* zombieHorde( int N, std::string name );

#endif
