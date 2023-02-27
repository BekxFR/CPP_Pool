#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	private:
	/* data */

	public:
	WrongCat();
	WrongCat(WrongCat const &obj);
	virtual ~WrongCat();
	WrongCat &operator=(WrongCat const &obj);

	void	makeSound(void) const;
};

#endif
