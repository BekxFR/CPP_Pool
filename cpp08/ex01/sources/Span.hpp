#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <limits.h>

class Span
{
	private:
		std::vector<int> _v;
		unsigned int _N;
		Span();

	public:
		Span(unsigned int N);
		Span(Span const &obj);
		~Span();
		Span &operator=(Span const &obj);

		unsigned int		getSize() const;
		std::vector<int>	getVector() const;

		void		addNumber(int const value);
		void		addRange(std::vector<int>::iterator const &begin, std::vector<int>::iterator const &end);
		long int	shortestSpan();
		long int	longestSpan();

		void		ChangeValue(int const target, int const value);
};

#endif
