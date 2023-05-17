#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {
	if (DEBUG)
		std::cout << "PmergeMe Default Constructor called" << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe& obj) {
	*this = obj;
}

PmergeMe::~PmergeMe() {
	if (DEBUG)
		std::cout << "PmergeMe Destructor called" << std::endl;
}

PmergeMe &PmergeMe::operator=(const PmergeMe& obj) {
	if (this != &obj)
		;
	if (DEBUG)
		std::cout << "PmergeMe Copy assignment operator called" << std::endl;
	return *this;
}
