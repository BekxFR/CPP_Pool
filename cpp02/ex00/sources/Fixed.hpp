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

#endif