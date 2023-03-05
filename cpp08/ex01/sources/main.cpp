/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chillion <chillion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 16:29:01 by chillion          #+#    #+#             */
/*   Updated: 2023/03/05 18:56:13 by chillion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	std::cout << "###OK addNumber Simple######" << std::endl;
{
	try
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
}
	std::cout << "###OK  shortest -1 et longest -1 ######" << std::endl;
{
	try
	{
		Span sp = Span(5);
		sp.addNumber(-4);
		sp.addNumber(-3);
		sp.addNumber(-16);
		sp.addNumber(-9);
		sp.addNumber(-11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
}
	std::cout << "###OK  shortest -1 et longest -1 ######" << std::endl;
{
	try
	{
		Span sp = Span(5);
		sp.addNumber(4);
		sp.addNumber(3);
		sp.addNumber(16);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
}
	std::cout << "###ERROR addNumber Simple######" << std::endl;
{
	try
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		sp.addNumber(23);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
}
std::cout << "###ERROR addNumber Range######" << std::endl;
{
	try
	{
	Span sp = Span(20000);
	std::vector<int> tmp;
	for (int i = 0; i < 20001; i++)
		tmp.push_back(i);
	sp.addNumber(tmp.begin(), tmp.end());
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
}
std::cout << "###OK addNumber Range######" << std::endl;
{
	try
	{
	Span sp = Span(20000);
	std::vector<int> tmp;
	for (int i = 0; i < 20000; i++)
		tmp.push_back(i);
	sp.addNumber(tmp.begin(), tmp.end());
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
}
std::cout << "###COPY AND CHANGE shortest to 1 (OR 0) AND ERROR addNumber Simple######" << std::endl;
{
	try
	{
	std::srand(time(0));
	Span sp = Span(20000);
	std::vector<int> tmp;
	for (int i = 0; i < 20000; i++)
		tmp.push_back((rand() % INT_MAX));
	std::cout << "TMP MIN = " << *std::min_element(tmp.begin(), tmp.end()) << std::endl;
	std::cout << "TMP MAX = " << *std::max_element(tmp.begin(), tmp.end()) << std::endl;
	std::cout << "TMP MAX DIF = " << *std::max_element(tmp.begin(), tmp.end()) - *std::min_element(tmp.begin(), tmp.end()) << std::endl;
	sp.addNumber(tmp.begin(), tmp.end());
	std::cout << "---BASE-----" << std::endl;
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	std::cout << "---COPY-----" << std::endl;
	Span cp_sp(sp);
	std::cout << cp_sp.shortestSpan() << std::endl;
	std::cout << cp_sp.longestSpan() << std::endl;
	std::cout << "---COPY MODIFY-----" << std::endl;
	cp_sp.changeValue(0, -10);
	cp_sp.changeValue(1, -11);
	std::cout << cp_sp.shortestSpan() << std::endl;
	std::cout << cp_sp.longestSpan() << std::endl;
	std::cout << "---BASE-----" << std::endl;
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std::cout << "---COPY 2-----" << std::endl;
	Span cp_sp2 = sp;
	std::cout << cp_sp2.shortestSpan() << std::endl;
	std::cout << cp_sp2.longestSpan() << std::endl;
	std::cout << "--------" << std::endl;
	cp_sp2.addNumber(11);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
}
std::cout << "###ERROR SIZE 0 addNumber Simple######" << std::endl;
{
	try
	{
		Span sp = Span(0);
		sp.addNumber(0);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
}
std::cout << "###ERROR SIZE < 2 NUMBER######" << std::endl;
{
	try
	{
		Span sp = Span(1);
		sp.addNumber(5);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
}
std::cout << "###OK SIZE == 2 0 0######" << std::endl;
{
	try
	{
		Span sp = Span(2);
		sp.addNumber(5);
		sp.addNumber(5);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
}
std::cout << "###OK SIZE == 2 0 0######" << std::endl;
{
	try
	{
		Span sp = Span(4);
		std::vector<int> tmp;
		tmp.push_back(1);
		tmp.push_back(10);
		sp.addNumber(tmp.begin(), tmp.end());
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		sp.addNumber(tmp.begin(), tmp.end());
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		sp.addNumber(tmp.begin(), tmp.end());
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
}
	return 0;
}