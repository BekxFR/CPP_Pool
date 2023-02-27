#include "Fixed.hpp"

Fixed::Fixed() : _rawBits(0)
{
}

Fixed::Fixed(int const value) : _rawBits(value << _bits)
{
}

Fixed::Fixed(float const value) : _rawBits(roundf(value * (1 << _bits)))
{
}

Fixed::Fixed(Fixed const &autre)
{
	*this = autre;
}

Fixed::~Fixed()
{
}

int	Fixed::getRawBits() const
{
	return (this->_rawBits);
}

void	Fixed::setRawBits(int const raw)
{
	this->_rawBits = raw;
}

float Fixed::toFloat(void) const
{
	return (static_cast<float>(this->getRawBits()) / (1 << _bits));
}

int Fixed::toInt(void) const
{
	return (static_cast<int>(this->getRawBits()) >> _bits);
}

Fixed	&Fixed::operator=(Fixed const &autre)
{
	this->_rawBits = autre.getRawBits();
	return *this;
}

bool	Fixed::operator>(Fixed const &autre) const
{
	return (this->getRawBits() > autre.getRawBits());
}

bool	Fixed::operator<(Fixed const &autre) const
{
	return (this->getRawBits() < autre.getRawBits());
}

bool	Fixed::operator>=(Fixed const &autre) const
{
	return (this->getRawBits() >= autre.getRawBits());
}

bool	Fixed::operator<=(Fixed const &autre) const
{
	return (this->getRawBits() <= autre.getRawBits());
}

bool	Fixed::operator==(Fixed const &autre) const
{
	return (this->getRawBits() == autre.getRawBits());
}

bool	Fixed::operator!=(Fixed const &autre) const
{
	return (this->getRawBits() != autre.getRawBits());
}

Fixed	Fixed::operator+(Fixed const &autre) const
{
	(void)autre;
	return (roundf(this->toFloat() + autre.toFloat()));
}

Fixed	Fixed::operator-(Fixed const &autre) const
{
	return (this->toFloat() - autre.toFloat());
}

Fixed	Fixed::operator*(Fixed const &autre) const
{
	return (this->toFloat() * autre.toFloat());
}

Fixed	Fixed::operator/(Fixed const &autre) const
{
	return (this->toFloat() / autre.toFloat());
}

Fixed	Fixed::operator++(int)
{
	Fixed temp(*this);
	operator++();
	return (temp);
}

Fixed	Fixed::operator--(int)
{
	Fixed temp(*this);
	operator--();
	return (temp);
}

Fixed	&Fixed::operator++()
{
	++this->_rawBits;
	return (*this);
}

Fixed	&Fixed::operator--()
{
	--this->_rawBits;
	return (*this);
}

Fixed Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b) ? a : b;
}
const Fixed Fixed::max(Fixed const &a, Fixed const &b)
{
	return (a > b) ? a : b;
}
Fixed Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b) ? a : b;
}
const Fixed Fixed::min(Fixed const &a, Fixed const &b)
{
	return (a < b) ? a : b;
}

std::ostream &operator<<(std::ostream &o, Fixed const &rhs)
{
	o << rhs.toFloat();
	return o;
}