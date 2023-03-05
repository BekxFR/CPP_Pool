/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chillion <chillion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 11:40:49 by chillion          #+#    #+#             */
/*   Updated: 2023/03/05 15:27:55 by chillion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

// int main()
// {
// 	int tab[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
// 	int tab2[] = { 23, 23, 23, 23, 23, 23, 23, 23, 23, 23 };

// 	iter(tab, 10, print);
// 	iter(tab2, 10, print);
// }

template<typename T>
void incrementer(T &valeur)
{
	++valeur;
}

template<typename T>
void afficher(T &valeur)
{
	std::cout << valeur << std::endl;
}

int main()
{
	int tableauEntier[] = {1, 2, 3, 4, 5};
	int tailleTabEntiers = sizeof(tableauEntier) / sizeof(int);

	// Test de la fonction iter avec le tableau d'entiers et la fonction incrementer
	std::cout << "Tableau d'entiers avant utilisation de la fonction iter :" << std::endl;
	for(int i = 0; i < tailleTabEntiers; ++i)
	{
		std::cout << tableauEntier[i] << " ";
	}
	std::cout << std::endl;

	iter(tableauEntier, tailleTabEntiers, incrementer);

	std::cout << "Tableau d'entiers après utilisation de la fonction iter avec incrementer :" << std::endl;
	for(int i = 0; i < tailleTabEntiers; ++i)
	{
		std::cout << tableauEntier[i] << " ";
	}
	std::cout << std::endl;

	// Test de la fonction iter avec le tableau d'entiers et la fonction afficher
	iter(tableauEntier, tailleTabEntiers, afficher); // == afficher<int>);

	float tableauFloat[] = {1.54f, 2.23f, 3.67f, 8.91f};
	int tailleTabFloats = sizeof(tableauFloat) / sizeof(float);

	// Test de la fonction iter avec le tableau de floats et la fonction afficher
	iter(tableauFloat, tailleTabFloats, afficher); // == afficher<float>);

	return 0;
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