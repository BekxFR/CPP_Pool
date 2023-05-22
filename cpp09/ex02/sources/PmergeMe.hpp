#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <typeinfo>
#include <sys/time.h>
#include <cstring>
#include <stdexcept>
#include <exception>

#define DEBUG 0

class PmergeMe
{
	private:
		bool	_status;

	public:
		PmergeMe();
		PmergeMe(PmergeMe const &obj);
		~PmergeMe();
		PmergeMe &operator=(PmergeMe const &obj);

		bool getStatus() { return this->_status; };

		void	ParseData(char **argv, int argc, int *tab);
		int		*checkArgsValues(char **argv, int argc, int *tab);


};

int onlyPositiveArgv(char *arg);

class NoPositiveInteger : public std::exception {
	public: 
		NoPositiveInteger(const char* message) : msg_(new char[28 + std::strlen(message)]) {
			std::strcpy(msg_, "Error: Wrong value find : ");
			std::strcat(msg_, message);
		}

		const char* what() const throw() {
			return msg_;
		}

		~NoPositiveInteger() throw() {
			delete [] msg_;
		}

	private:
		char* msg_;
};

#endif
