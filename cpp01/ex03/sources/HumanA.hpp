#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
private:
	std::string _name;
	Weapon &_weapon; //Ref because ref cant be NULL and HumanA need to have weapon

public:
	HumanA(std::string name, Weapon &weapon);
	~HumanA();
	void attack();
};

#endif