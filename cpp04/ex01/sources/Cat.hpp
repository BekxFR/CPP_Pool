#ifndef CAT_HPP
#define CAT_HPP

#include "Dog.hpp"

class Cat : public Animal
{
	private:
	Brain *_brain;

	public:
	Cat();
	Cat(Cat const &obj);
	virtual ~Cat();
	Cat &operator=(Cat const &obj);

	void	makeSound(void) const;

	Brain	*getBrain() const;

	void	setIdea(std::string const &ideas, int const &idea);
	void	printIdea(int const &idea) const;
};

#endif
