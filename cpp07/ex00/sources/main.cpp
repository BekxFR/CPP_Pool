#include "whatever.hpp"

int main( void )
{
	int a = 3;
	int b = 3;
{
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "a = " << &a << ", b = " << &b << std::endl;
	int &T2 = max2( a, b );
	std::cout << "T2 = " << T2 << std::endl;
	std::cout << "T2 = " << &T2 << std::endl;
	int &T3 = min2( a, b );
	std::cout << "T3 = " << T3 << std::endl;
	std::cout << "T3 = " << &T3 << std::endl;
}

	std::cout << "######################################" << std::endl;

	swap( a, b );
{
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "a = " << &a << ", b = " << &b << std::endl;
	int &T2 = max2( a, b );
	std::cout << "T2 = " << T2 << std::endl;
	std::cout << "T2 = " << &T2 << std::endl;
	int &T3 = min2( a, b );
	std::cout << "T3 = " << T3 << std::endl;
	std::cout << "T3 = " << &T3 << std::endl;
}

	a = 2;
	b = 3;
	std::cout << "######################################" << std::endl;

	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "a = " << &a << ", b = " << &b << std::endl;
	std::cout << "min( a, b ) = " << min( a, b ) << std::endl;
{
	int &T = min2( a, b );
	std::cout << "T = " << T << std::endl;
	std::cout << "T = " << &T << std::endl;
}
	std::cout << "max( a, b ) = " << max( a, b ) << std::endl;
{
		int &T = max2( a, b );
	std::cout << "T = " << T << std::endl;
	std::cout << "T = " << &T << std::endl;
}
	swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "a = " << &a << ", b = " << &b << std::endl;
	std::cout << "min( a, b ) = " << min( a, b ) << std::endl;
{
	int &T = min2( a, b );
	std::cout << "T = " << T << std::endl;
	std::cout << "T = " << &T << std::endl;
}
	std::cout << "max( a, b ) = " << max( a, b ) << std::endl;
{
		int &T = max2( a, b );
	std::cout << "T = " << T << std::endl;
	std::cout << "T = " << &T << std::endl;
}

	std::cout << "######################################" << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "c = " << &c << ", d = " << &d << std::endl;
	std::cout << "min( c, d ) = " << min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << max( c, d ) << std::endl;
	swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "c = " << &c << ", d = " << &d << std::endl;
	std::cout << "min( c, d ) = " << min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << max( c, d ) << std::endl;
	return 0;
}

// class Awesome
// {
// 	public:
// 		Awesome(void) : _n(0)
// 		{}
// 		Awesome( int n ) : _n( n )
// 		{}
// 		Awesome & operator= (Awesome & a)
// 		{
// 			_n = a._n; return *this;
// 		}
// 		bool operator==( Awesome const & rhs ) const
// 		{
// 			return (this->_n == rhs._n);
// 		}
// 		bool operator!=( Awesome const & rhs ) const
// 		{
// 			return (this->_n != rhs._n);
// 		}
// 		bool operator>( Awesome const & rhs ) const
// 		{
// 			return (this->_n > rhs._n);
// 		}
// 		bool operator<( Awesome const & rhs ) const
// 		{
// 			return (this->_n < rhs._n);
// 		}
// 		bool operator>=( Awesome const & rhs ) const
// 		{
// 			return (this->_n >= rhs._n);
// 		}
// 		bool operator<=( Awesome const & rhs ) const
// 		{
// 			return (this->_n <= rhs._n);
// 		}
// 		int get_n() const { return _n; }
// 	private:
// 		int _n;
// };

// std::ostream & operator<<(std::ostream & o, const Awesome &a)
// {
// 	o << a.get_n();
// 	return o;
// }

// int main(void)
// {
// 	Awesome a(2), b(4);

// 	::swap(a, b);
// 	std::cout << a << " " << b << std::endl;
// 	std::cout << max(a, b) << std::endl;
// 	std::cout << min(a, b) << std::endl;
// ::swap(a, b);
// 	std::cout << a << " " << b << std::endl;
// 	std::cout << max(a, b) << std::endl;
// 	std::cout << min(a, b) << std::endl;
// 	return (0);
// }
