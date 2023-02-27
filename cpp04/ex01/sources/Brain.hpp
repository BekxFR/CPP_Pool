#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
	private:
	void	setBrain(std::string const ideas);
	std::string _ideas[100];

	public:
	Brain();
	Brain(Brain const &obj);
	~Brain();
	Brain &operator=(Brain const &obj);

	void	setIdea(std::string const &ideas, int const &idea);

	void		printIdea(int const &idea) const;
	std::string	getIdea(int const &idea) const;
};

#endif
