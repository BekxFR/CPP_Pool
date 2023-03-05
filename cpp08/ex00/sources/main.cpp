/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chillion <chillion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 12:07:08 by chillion          #+#    #+#             */
/*   Updated: 2023/03/05 16:24:46 by chillion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
	std::vector<int> v;

	if (easyfind(v, 2) == v.end()) // == easyfind<std::vector<int> >(v, 2) == v.end()
		std::cout << "Value not found !" << std::endl;
	else
		std::cout << "Value match !" << std::endl;

	v.push_back(1);
	v.push_back(2);
	v.push_back(3);

	if (easyfind<std::vector<int> >(v, 2) == v.end())
		std::cout << "Value not found !" << std::endl;
	else
		std::cout << "Value match !" << std::endl;

	if (easyfind<std::vector<int> >(v, 5) == v.end())
		std::cout << "Value not found !" << std::endl;
	else
		std::cout << "Value match !" << std::endl;

	if (easyfind<std::vector<int> >(v, 3) == v.end())
		std::cout << "Value not found !" << std::endl;
	else
		std::cout << "Value match !" << std::endl;

	std::cout << "#########################################" << std::endl;

	std::list<int> l;

	if (easyfind<std::list<int> >(l, 2) == l.end())
		std::cout << "Value not found !" << std::endl;
	else
		std::cout << "Value match !" << std::endl;

	l.push_back(1);
	l.push_back(2);
	l.push_back(3);

	if (easyfind<std::list<int> >(l, 2) == l.end())
		std::cout << "Value not found !" << std::endl;
	else
		std::cout << "Value match !" << std::endl;

	if (easyfind<std::list<int> >(l, 5) == l.end())
		std::cout << "Value not found !" << std::endl;
	else
		std::cout << "Value match !" << std::endl;

	if (easyfind<std::list<int> >(l, 3) == l.end())
		std::cout << "Value not found !" << std::endl;
	else
		std::cout << "Value match !" << std::endl;

	std::cout << "#########################################" << std::endl;

	std::deque<int> d;

	if (easyfind<std::deque<int> >(d, 2) == d.end())
		std::cout << "Value not found !" << std::endl;
	else
		std::cout << "Value match !" << std::endl;

	d.push_back(1);
	d.push_back(2);
	d.push_back(3);

	if (easyfind<std::deque<int> >(d, 2) == d.end())
		std::cout << "Value not found !" << std::endl;
	else
		std::cout << "Value match !" << std::endl;

	if (easyfind<std::deque<int> >(d, 5) == d.end())
		std::cout << "Value not found !" << std::endl;
	else
		std::cout << "Value match !" << std::endl;

	if (easyfind<std::deque<int> >(d, 3) == d.end())
		std::cout << "Value not found !" << std::endl;
	else
		std::cout << "Value match !" << std::endl;

	std::cout << "#########################################" << std::endl;

	std::vector<int> v2;

	if (easyfind<std::vector<int> >(v2, 2) == v2.end())
		std::cout << "Value not found !" << std::endl;
	else
		std::cout << "Value match !" << std::endl;

	std::srand(time(0));
	long int ref = 0;
	for (int i = 0; i < 20000; i++)
	{
		if (i == 10000)
		{
			ref = (rand() % INT_MAX);
			v2.push_back(ref);
		}
		else
			v2.push_back((rand() % INT_MAX));
	}

	if (easyfind<std::vector<int> >(v2, (rand() % INT_MAX)) == v2.end())
		std::cout << "Value not found !" << std::endl;
	else
		std::cout << "Value match !" << std::endl;

	if (easyfind<std::vector<int> >(v2, ref) == v2.end())
		std::cout << "Value not found !" << std::endl;
	else
		std::cout << "Value match !" << std::endl;

	if (easyfind<std::vector<int> >(v2, (rand() % INT_MAX)) == v2.end())
		std::cout << "Value not found !" << std::endl;
	else
		std::cout << "Value match !" << std::endl;

	std::cout << "Vector size value = " << v2.size() << std::endl;
	
	std::cout << "#########################################" << std::endl;

	return (0);
}
