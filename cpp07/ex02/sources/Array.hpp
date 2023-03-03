/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chillion <chillion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 13:02:48 by chillion          #+#    #+#             */
/*   Updated: 2023/03/03 11:39:30 by chillion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <typeinfo>


template <typename T>
class Array
{
	private:
		T *_array;
		unsigned int _size;

	public:
		Array();
		Array(unsigned int n);
		Array(Array const &obj);
		~Array();
		Array &operator=(Array const &obj);
		T &operator[](unsigned int idx);
		// T &operator[](unsigned int idx) const;
		std::size_t	size() const;
};

#include "Array.tpp"

#endif
