#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
	private:

	protected:
	std::string _type;

	public:
	WrongAnimal();
	WrongAnimal(std::string const &type);
	WrongAnimal(WrongAnimal const &obj);
	virtual ~WrongAnimal();
	WrongAnimal &operator=(WrongAnimal const &obj);

	void	setType(std::string const &type);

	const std::string	&getType() const;

	void	makeSound(void) const;
};

#endif
