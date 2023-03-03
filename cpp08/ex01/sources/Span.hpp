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
		unsigned int _N;
		std::vector<int> _v;
		Span();

	public:
		Span(unsigned int N);
		Span(Span const &obj);
		~Span();
		Span &operator=(Span const &obj);

		void addNumber(int const value)
		{
				if (this->_N == _v.size())
					throw std::length_error("Unaccepted size overflow");
				_v.push_back(value);
		}
		int shortestSpan()
		{
			if (_v.size() <= 1)
				throw std::length_error("Not enaugh value for shortestSpan");
			int min_span = INT_MAX;
			std::vector<int> tmp = _v;
			std::sort(tmp.begin(), tmp.end());
			for (std::vector<int>::iterator it_tmp = tmp.begin(); it_tmp != tmp.end(); ++it_tmp)
			{
				int span = *(it_tmp + 1) - *it_tmp;
				if (span < min_span)
					min_span = span;
			}
			return (min_span);
		}
		int longtestSpan()
		{
			if (_v.size() <= 1)
				throw std::length_error("Not enaugh value for longtestSpan");
			int max_span = 0;
			std::vector<int> tmp = _v;
			std::sort(tmp.begin(), tmp.end());
			for (std::vector<int>::iterator it_tmp = tmp.begin(); it_tmp != tmp.end(); ++it_tmp)
			{
				int span = *(it_tmp + 1) - *it_tmp;
				if (span > max_span)
					max_span = span;
			}
			return (max_span);

		}
};

#endif
