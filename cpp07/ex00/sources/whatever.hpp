/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chillion <chillion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 12:15:24 by chillion          #+#    #+#             */
/*   Updated: 2023/03/05 15:00:10 by chillion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template <typename T>
T max (T &a, T &b)
{
	return (a > b ? a : b);
}

template <typename T>
T &max2 (T &a, T &b)
{
	return (a > b ? a : b);
}

template <typename T>
T min (T &a, T &b)
{
	return (a < b ? a : b);
}

template <typename T>
T &min2 (T &a, T &b)
{
	return (a < b ? a : b);
}

template <typename T>
void swap (T &a, T &b)
{
	T tmp = b;
	b = a;
	a = tmp;
}

#endif

