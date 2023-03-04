#include "Span.hpp"

Span::Span() : _N(0)
{
	_v.reserve(0);
	std::cout << "Span Default Constructor called" << std::endl;
}

Span::Span(unsigned int N) : _N(N)
{
	_v.reserve(N);
	std::cout << "Span Overload Constructor called" << std::endl;
}
Span::Span(Span const &obj)// : _v(this->getVector()), _N(this->getSize())
{
	*this = obj;
}
Span::~Span()
{
	std::cout << "Span Destructor called" << std::endl;
}
Span &Span::operator=(Span const &obj)
{
	this->_v = obj.getVector();
	this->_N = obj.getSize();
	std::cout << "Span Copy assignment operator called" << std::endl;
	return *this;
}

unsigned int Span::getSize() const
{
	return (this->_N);
}

std::vector<int> Span::getVector() const
{
	return (this->_v);
}

void Span::addNumber(int const value)
{
		if (this->_N == _v.size())
			throw std::length_error("Unaccepted size overflow for addNumber");
		_v.push_back(value);
}

long int Span::shortestSpan()
{
	if (_v.size() <= 1)
		throw std::length_error("Not enaugh value for shortestSpan");
	long int min_span = INT_MAX;
	std::vector<int> tmp = _v;
	std::sort(tmp.begin(), tmp.end());
	for (std::vector<int>::iterator it_tmp = tmp.begin(); (it_tmp + 1)!= tmp.end(); ++it_tmp)
	{
		long int span = *(it_tmp + 1) - *it_tmp;
		if (span < min_span)
			min_span = span;
	}
	return (min_span);
}

long int Span::longestSpan()
{
	if (_v.size() <= 1)
		throw std::length_error("Not enaugh value for longtestSpan");
	long int min_span = *std::min_element(_v.begin(), _v.end());
	long int max_span = *std::max_element(_v.begin(), _v.end());
	return (max_span - min_span);
}

void Span::addRange(std::vector<int>::iterator const &begin, std::vector<int>::iterator const &end)
{
	if (_v.size() + std::distance(begin, end) > this->_N)
		throw std::length_error("Unaccepted size overflow for addRange");
	_v.insert(_v.end(), begin, end);
}

void Span::ChangeValue(int const target, int const value)
{
	_v.at(target) = value;
}