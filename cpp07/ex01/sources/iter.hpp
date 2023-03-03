/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chillion <chillion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 11:13:21 by chillion          #+#    #+#             */
/*   Updated: 2023/03/02 17:08:29 by chillion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template<class T>
void iter(T *array, int arraySize, void (*f)(T&))
{
	for(int i = 0; i < arraySize; ++i)
	{
		T &element = array[i];
		f(element);
	}
}

template<class T >
void print(T &x)
{
	std::cout << x << std::endl;
	return;
}

#endif
