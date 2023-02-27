#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"

class Dog : public AAnimal
{
	private:
	Brain *_brain;

	public:
	Dog();
	Dog(Dog const &obj);
	virtual ~Dog();
	Dog &operator=(Dog const &obj);

	void	makeSound(void) const;

	Brain	*getBrain() const;

	void	setIdea(std::string const &ideas, int const &idea);
	void	printIdea(int const &idea) const;
};

#endif
