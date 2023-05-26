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

const int TAILLE_SEUIL = 10;

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
		void	Routine_For_Vector_List_Tri(int argc, char **argv);
};

int			onlyDigitArgv(char *arg);
void		rangeList(std::list<int>::iterator start, std::list<int>::iterator end);
void		printSortStatus(size_t size, std::string type, float time);
long long	getTimeInMicroseconds();
time_t		getTime();
double		getTimeElapsedInMicroseconds(struct timeval startTime, struct timeval endTime);

void	merge_Insertion_Sort_List(std::list<int>& arr, int debut, int fin);
void	merge_Insertion_Sort(std::vector<int>& arr, int debut, int fin);

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

template <typename T>
void myPrintTemplate(const T& arr);

template <typename T>
void myOneLinePrintTemplate(const T& arr, const std::string& text);

template <typename T>
void myItPrintTemplate(T b, T e);

#endif
