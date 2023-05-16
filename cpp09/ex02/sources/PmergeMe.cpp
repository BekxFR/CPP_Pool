#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
	if (DEBUG)
		std::cout << "PmergeMe Default Constructor called" << std::endl;
}

PmergeMe::PmergeMe(PmergeMe const &obj)
{
	*this = obj;
}

PmergeMe::~PmergeMe()
{
	if (DEBUG)
		std::cout << "PmergeMe Destructor called" << std::endl;
}

PmergeMe &PmergeMe::operator=(PmergeMe const &obj)
{
	if (DEBUG)
		std::cout << "PmergeMe Copy assignment operator called" << std::endl;
	return *this;
}