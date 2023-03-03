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
