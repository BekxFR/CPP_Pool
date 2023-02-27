#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
	private:
	/* data */

	public:
	Dog();
	Dog(Dog const &obj);
	virtual ~Dog();
	Dog &operator=(Dog const &obj);

	void	makeSound(void) const;
};

#endif