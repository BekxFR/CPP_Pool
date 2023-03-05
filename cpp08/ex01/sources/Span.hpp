/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chillion <chillion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 16:29:11 by chillion          #+#    #+#             */
/*   Updated: 2023/03/05 18:48:44 by chillion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <limits.h>

class Span
{
	private:
		std::vector<int> _v;
		unsigned int _N;
		Span();

	public:
		Span(unsigned int N);
		Span(Span const &obj);
		~Span();
		Span &operator=(Span const &obj);

		unsigned int		getSize() const;
		std::vector<int>	getVector() const;

		void		addNumber(int const value);
		void		addNumber(std::vector<int>::const_iterator const begin, std::vector<int>::const_iterator const end);
		long int	shortestSpan();
		long int	longestSpan();

		void		changeValue(int const target, int const value);
};

#endif
