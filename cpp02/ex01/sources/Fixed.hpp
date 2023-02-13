#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
	int _value;
	static const int _bits;
public:
	Fixed();
	Fixed(Fixed const &autre);
	~Fixed();
	void	operator=(const Fixed &autre);
	int	getRawBits() const;
	void	setRawBits(int const raw);

};

Fixed::Fixed() : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &autre) : _value(autre._value)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = autre;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

void	Fixed::operator=(const Fixed &autre)
{
	std::cout << "Copy assignment operator called" << std::endl;
	_value = autre.getRawBits();
}

int	Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

void	Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

#endif