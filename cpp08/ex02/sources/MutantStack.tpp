/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chillion <chillion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 16:51:08 by chillion          #+#    #+#             */
/*   Updated: 2023/03/05 19:05:41 by chillion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"


template<typename T>
MutantStack<T>::MutantStack() : std::stack<T>()
{
	std::cout << "MutantStack Default Constructor called" << std::endl;
}

// template<typename T>
// MutantStack<T>::MutantStack() : std::stack<T, std::vector<T> >()
// {
// 	std::cout << "MutantStack Default Constructor called" << std::endl;
// }

template<typename T>
MutantStack<T> &MutantStack<T>::operator=(MutantStack<T> const &obj)
{
	std::cout << "MutantStack Copy assignment operator called" << std::endl;
	if (this == &obj)
		return (*this);
	std::stack<T>::operator=(obj);
	return (*this);
}

template<typename T>
MutantStack<T>::MutantStack(const MutantStack<T> &obj) : std::stack<T>(obj)
{
	std::cout << "MutantStack Copy Constructor called" << std::endl;
}

// template<typename T>
// MutantStack<T>::MutantStack(const MutantStack<T> &obj) : std::stack<T, std::vector<T> >(obj)
// {
// 	std::cout << "MutantStack Copy Constructor called" << std::endl;
// }

template<typename T>
MutantStack<T>::~MutantStack()
{
	std::cout << "MutantStack Destructor called" << std::endl;
}

// Renvoie un itérateur sur le début du mutant stack
template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return this->c.begin();
}

// Renvoie un itérateur sur la fin du mutant stack
template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return this->c.end();
}

// Renvoie un const-itérateur sur le début du mutant stack
template<typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::cbegin() const
{
	return this->c.begin();
}

// Renvoie un const-itérateur sur la fin du mutant stack
template<typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::cend() const
{
	return this->c.end();
}

// Renvoie un itérateur inversé sur le début du mutant stack
template<typename T>
typename MutantStack<T>::reverse_iterator  MutantStack<T>::rbegin()
{
	return this->c.rbegin();
}
// Renvoie un itérateur inversé sur la fin du mutant stack
template<typename T>
typename MutantStack<T>::reverse_iterator  MutantStack<T>::rend()
{
	return this->c.rend();
}

// Renvoie un const-itérateur inversé sur le début du mutant stack
template<typename T>
typename MutantStack<T>::const_reverse_iterator  MutantStack<T>::crbegin() const
{
	return this->c.rbegin();
}
// Renvoie un const-itérateur inversé sur la fin du mutant stack
template<typename T>
typename MutantStack<T>::const_reverse_iterator  MutantStack<T>::crend() const
{
	return this->c.rend();
}