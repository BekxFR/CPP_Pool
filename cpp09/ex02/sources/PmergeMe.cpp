#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : _status(false) {
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
		_status = obj._status;
	if (DEBUG)
		std::cout << "PmergeMe Copy assignment operator called" << std::endl;
	return *this;
}

int *PmergeMe::checkArgsValues(char **argv, int argc, int *tab)
{
	// int tab[argc - 1];

	for (int i = 1; i < argc; i++) {
		if (onlyPositiveArgv(argv[i]) == 1)
			throw NoPositiveInteger(argv[i]);
		else
		{
			if (DEBUG)
				std::cout << "std::atoi(argv[" << i << "]) = " << std::atoi(argv[i]) << std::endl;
			tab[i - 1] = std::atoll(argv[i]);
		}
	}
	return (0);
}

void PmergeMe::ParseData(char **argv, int argc, int *tab)
{
	try
	{
		// tab = this->checkArgsValues(argv, argc);
		this->checkArgsValues(argv, argc, tab);
	}
	catch (NoPositiveInteger &e)
	{
		std::cout << e.what() << std::endl;
	}
}