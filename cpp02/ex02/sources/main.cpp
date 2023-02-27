#include "Fixed.hpp"

int main( void )
{
	Fixed a;
	Fixed c(5);
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

	std::cout << "\nOTHER TESTS" << std::endl;
	a = 5;
	c = 500;
	std::cout << "a = " << a << std::endl;
	std::cout << "c = " << c << std::endl;
	std::cout << "(a + c) = " << (a + c) << std::endl;
	std::cout << "(a - c) = " << (a - c) << std::endl;
	std::cout << "(a * c) = " << (a * c) << std::endl;
	std::cout << "(a / c) = " << (a / c) << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "(a + b) = " << (a + b) << std::endl;
	std::cout << "(a - b) = " << (a - b) << std::endl;
	std::cout << "(a * b) = " << (a * b) << std::endl;
	std::cout << "(a / b) = " << (a / b) << std::endl;
	std::cout << "(c++) = " << (c++) << std::endl;
	std::cout << "(c) = " << (c) << std::endl;
	std::cout << "(++c) = " << (++c) << std::endl;
	std::cout << "(a++) = " << (a++) << std::endl;
	std::cout << "(a) = " << (a) << std::endl;
	std::cout << "(++a) = " << (++a) << std::endl;
	std::cout << "Fixed::max( a, b ) = " << Fixed::max( a, b ) << std::endl;
	std::cout << "Fixed::min( a, b ) = " << Fixed::min( a, b ) << std::endl;
	return 0;
}