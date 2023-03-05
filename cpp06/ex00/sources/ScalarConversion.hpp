/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConversion.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chillion <chillion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:52:27 by chillion          #+#    #+#             */
/*   Updated: 2023/03/01 16:52:28 by chillion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERSION_HPP
#define SCALARCONVERSION_HPP

#include <iostream>
#include <string>
#include <limits>
#include <cstdlib>
#include <cctype>
#include <limits.h>

class ScalarConversion
{
	private:
		ScalarConversion();
		ScalarConversion(ScalarConversion const &obj);
		~ScalarConversion();
		ScalarConversion &operator=(ScalarConversion const &obj);

	public:
		static bool	isChar(std::string str);
		static bool	isInt(std::string str);
		static bool	isFloat(std::string str);
		static bool	isDouble(std::string str);

		static void	convert(std::string const &str);

		static void	displayChar(char _char);
		static void	displayInt(int _int);
		static void	displayFloat(float _float, std::string str);
		static void	displayDouble(double _double, std::string str);
};

#endif
