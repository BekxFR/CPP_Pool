/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chillion <chillion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 16:22:39 by chillion          #+#    #+#             */
/*   Updated: 2023/03/05 16:22:40 by chillion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <deque>
#include <limits.h>

template<typename T>
typename T::iterator easyfind(T &t, int const int_search);

#include "easyfind.tpp"

#endif