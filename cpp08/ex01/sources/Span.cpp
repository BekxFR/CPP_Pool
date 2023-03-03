#include "Span.hpp"

Span::Span()
{
	std::cout << "Span Default Constructor called" << std::endl;
}

Span::Span(unsigned int N)
{
	std::cout << "Span Overload Constructor called" << std::endl;
}
Span::Span(Span const &obj)
{
	*this = obj;
}
Span::~Span()
{
	std::cout << "Span Destructor called" << std::endl;
}
Span &Span::operator=(Span const &obj)
{
	std::cout << "Span Copy assignment operator called" << std::endl;
	return *this;
}
