/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chillion <chillion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:38:56 by chillion          #+#    #+#             */
/*   Updated: 2023/03/01 16:38:57 by chillion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConversion.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error : Scalar Conversion need one parameter !" << std::endl;
		return (1);
	}
	if (std::atol(argv[1]) > INT_MAX || std::atol(argv[1]) < INT_MIN)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return (1);
	}
	ScalarConversion::convert(argv[1]);
	return (0);
}