#ifndef CAT_HPP
#define CAT_HPP

#include "Dog.hpp"

class Cat : public Animal
{
	private:
	/* data */

	public:
	Cat();
	Cat(Cat const &obj);
	virtual ~Cat();
	Cat &operator=(Cat const &obj);

	void	makeSound(void) const;
};

#endif
