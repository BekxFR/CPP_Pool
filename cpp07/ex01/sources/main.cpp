/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chillion <chillion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 11:40:49 by chillion          #+#    #+#             */
/*   Updated: 2023/03/02 17:08:19 by chillion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main()
{
	int tab[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
	int tab2[] = { 23, 23, 23, 23, 23, 23, 23, 23, 23, 23 };

	iter(tab, 10, print);
	iter(tab2, 10, print);
}

// class Awesome
// {
// 	public:
// 		Awesome( void ) : _n( 42 ) { return; }
// 		int get( void ) const { return this->_n; }
// 	private:
// 		int _n;
// };

// std::ostream & operator<<( std::ostream & o, Awesome const & rhs )
// {
// 	o << rhs.get(); return o;
// }

// // template<typename T >
// // void print(T &x)
// // {
// // 	std::cout << x << std::endl;
// // 	return;
// // }

// int main()
// {
// 	int tab[] = { 0, 1, 2, 3, 4 }; // <--- I never understood why you can't write int[] tab. Wouldn't that make more sense?
// 	Awesome tab2[5];

// 	iter( tab, 5, print );
// 	iter( tab2, 5, print );

// 	return 0;
// }