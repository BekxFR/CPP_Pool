#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>

#define DEBUG 0

class PmergeMe
{
	private:
		/* data */

	public:
		PmergeMe();
		PmergeMe(PmergeMe const &obj);
		~PmergeMe();
		PmergeMe &operator=(PmergeMe const &obj);
};

#endif
