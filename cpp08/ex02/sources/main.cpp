/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chillion <chillion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 16:50:59 by chillion          #+#    #+#             */
/*   Updated: 2023/03/05 19:05:14 by chillion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>

int main()
{
	{
		try
		{
			MutantStack<int> mstack;
			mstack.push(5);
			mstack.push(17);
			std::cout << mstack.top() << std::endl;
			mstack.pop();
			std::cout << mstack.size() << std::endl;
			mstack.push(3);
			mstack.push(5);
			mstack.push(737);
			//[...]
			mstack.push(0);
			MutantStack<int>::iterator it = mstack.begin();
			MutantStack<int>::iterator ite = mstack.end();
			++it;
			--it;
			while (it != ite)
			{
				std::cout << *it << std::endl;
				++it;
			}
			// std::stack<int, std::vector<int> > s(mstack);
			std::stack<int> s(mstack);
		}
		catch (const std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		try
		{
			std::list<int> mstack;
			mstack.push_back(5);
			mstack.push_back(17);
			std::cout << mstack.back() << std::endl;
			mstack.pop_back();
			std::cout << mstack.size() << std::endl;
			mstack.push_back(3);
			mstack.push_back(5);
			mstack.push_back(737);
			//[...]
			mstack.push_back(0);
			std::list<int>::iterator it = mstack.begin();
			std::list<int>::iterator ite = mstack.end();
			++it;
			--it;
			while (it != ite)
			{
				std::cout << *it << std::endl;
				++it;
			}
			std::list<int> s(mstack);
		}
		catch (const std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "###MutantStack#############################################" << std::endl;
	{
		try
		{
			MutantStack<int> mutantStack;
			for (int i = 0; i < 5; ++i)
			{
				mutantStack.push(i);
			}

			std::cout << "En parcourant avec un itérateur normal : ";
			for (MutantStack<int>::iterator it = mutantStack.begin(); it != mutantStack.end(); ++it)
			{
				std::cout << *it << " ";
			}

			std::cout << "\nEn parcourant avec un const-itérateur : ";
			for (MutantStack<int>::const_iterator cit = mutantStack.cbegin(); cit != mutantStack.cend(); ++cit)
			{
				std::cout << *cit << " ";
			}

			std::cout << "\nEn parcourant avec un itérateur inversé : ";
			for (MutantStack<int>::reverse_iterator it = mutantStack.rbegin(); it != mutantStack.rend(); ++it)
			{
				std::cout << *it << " ";
			}

			std::cout << "\nEn parcourant avec un const-itérateur inversé : ";
			for (MutantStack<int>::const_reverse_iterator rit = mutantStack.crbegin(); rit != mutantStack.crend(); ++rit)
			{
				std::cout << *rit << " ";
			}
			std::cout << std::endl;

			std::cout << "En parcourant avec un itérateur normal : ";
			for (MutantStack<int>::iterator it = mutantStack.end() - 1; it != mutantStack.begin(); --it)
			{
				std::cout << *it << " ";
			}
			std::cout << *mutantStack.begin();
			std::cout << "\nEn parcourant avec un const-itérateur : ";
			for (MutantStack<int>::const_iterator cit = mutantStack.cend() - 1; cit != mutantStack.cbegin(); --cit)
			{
				std::cout << *cit << " ";
			}
			std::cout << *mutantStack.cbegin();
			std::cout << "\nEn parcourant avec un itérateur inversé : ";
			for (MutantStack<int>::reverse_iterator it = mutantStack.rend() - 1; it != mutantStack.rbegin(); --it)
			{
				std::cout << *it << " ";
			}
			std::cout << *mutantStack.rbegin();
			std::cout << "\nEn parcourant avec un const-itérateur inversé : ";
			for (MutantStack<int>::const_reverse_iterator rit = mutantStack.crend() - 1; rit != mutantStack.crbegin(); --rit)
			{
				std::cout << *rit << " ";
			}
			std::cout << *mutantStack.crbegin() << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "###List#############################################" << std::endl;
	{
		try
		{
			std::list<int> mutantStack;
			for (int i = 0; i < 5; ++i)
			{
				mutantStack.push_back(i);
			}

			std::cout << "En parcourant avec un itérateur normal : ";
			for (std::list<int>::iterator it = mutantStack.begin(); it != mutantStack.end(); ++it)
			{
				std::cout << *it << " ";
			}

			std::cout << "\nEn parcourant avec un const-itérateur : ";
			for (std::list<int>::const_iterator cit = mutantStack.begin(); cit != mutantStack.end(); ++cit)
			{
				std::cout << *cit << " ";
			}

			std::cout << "\nEn parcourant avec un itérateur inversé : ";
			for (std::list<int>::reverse_iterator it = mutantStack.rbegin(); it != mutantStack.rend(); ++it)
			{
				std::cout << *it << " ";
			}

			std::cout << "\nEn parcourant avec un const-itérateur inversé : ";
			for (std::list<int>::const_reverse_iterator rit = mutantStack.rbegin(); rit != mutantStack.rend(); ++rit)
			{
				std::cout << *rit << " ";
			}
			std::cout << std::endl;

			std::cout << "En parcourant avec un itérateur normal : ";
			std::list<int>::iterator it = mutantStack.end();
			--it;
			for (; it != mutantStack.begin(); --it)
			{
				std::cout << *it << " ";
			}
			std::cout << *it;
			std::list<int>::const_iterator cit = mutantStack.end();
			--cit;
			std::cout << "\nEn parcourant avec un const-itérateur : ";
			for (; cit != mutantStack.begin(); --cit)
			{
				std::cout << *cit << " ";
			}
			std::cout << *cit;
			std::list<int>::reverse_iterator it2 = mutantStack.rend();
			--it2;
			std::cout << "\nEn parcourant avec un itérateur inversé : ";
			for (; it2 != mutantStack.rbegin(); --it2)
			{
				std::cout << *it2 << " ";
			}
			std::cout << *it2;
			std::list<int>::const_reverse_iterator rit = mutantStack.rend();
			--rit;
			std::cout << "\nEn parcourant avec un const-itérateur inversé : ";
			for (; rit != mutantStack.rbegin(); --rit)
			{
				std::cout << *rit << " ";
			}
			std::cout << *rit << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	return (0);
}