#include "ScalarConversion.hpp"

ScalarConversion::ScalarConversion()
{
	std::cout << "ScalarConversion Default Constructor called" << std::endl;
}

ScalarConversion::ScalarConversion(ScalarConversion const &obj)
{
	std::cout << "ScalarConversion Copy Constructor called" << std::endl;
	*this = obj;
}

ScalarConversion::~ScalarConversion()
{
	std::cout << "ScalarConversion Destructor called" << std::endl;
}

ScalarConversion &ScalarConversion::operator=(ScalarConversion const &obj)
{
	(void)obj;
	std::cout << "ScalarConversion Copy assignment operator called" << std::endl;
	return *this;
}

bool ScalarConversion::isChar(std::string str)
{
	if (str.size() == 1 && !std::isdigit(str[0]))
		return (true);
	return (false);
}

bool ScalarConversion::isInt(std::string str)
{
	unsigned long int	i = 0;

	if (str[0] == '-' || str[0] == '+')
		i++;
	while (std::isdigit(str[i]))
		i++;
	if (str.size() == i)
		return (true);
	return (false);
}

bool ScalarConversion::isFloat(std::string str)
{
	unsigned long int	i = 0;
	
	if (str == "-inff" || str == "+inff" || str == "nanf")
		return (true);
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (std::isdigit(str[i]))
		i++;
	if (str[i] == '.' && std::isdigit(str[i + 1]))
		i++;
	else
		return (false);
	while (std::isdigit(str[i]))
		i++;
	if (str[i] == 'f')
		i++;
	else
		return (false);
	if (str.size() == i)
		return (true);
	return (false);
}

bool ScalarConversion::isDouble(std::string str)
{
	unsigned long int	i = 0;
	
	if (str == "-inf" || str == "+inf" || str == "nan")
		return (true);
	if (str[0] == '-' || str[0] == '-')
		i++;
	while (std::isdigit(str[i]))
		i++;
	if (str[i] == '.' && std::isdigit(str[i + 1]))
		i++;
	while (std::isdigit(str[i]))
		i++;
	if (str.size() == i)
		return (true);
	return (false);
}

void ScalarConversion::convert(std::string const &str)
{
	enum type {CHAR, INT, FLOAT, DOUBLE};
	bool (*ftab[5])(std::string str) = {isChar, isInt, isFloat, isDouble, NULL};
	unsigned long int	n = 0;
	char				_char = 0;
	int					_int = 0;
	float				_float = 0.0f;
	double				_double = 0.0;

	for (; n < 5; n++)
	{
		if (n != 4 && ftab[n](str) == true)
			break ;
	}
	switch (n)
	{
		case CHAR :
			_char = str[0];
			displayChar(_char);
			break;
		case INT :
			_int = atoi(str.c_str());
			displayInt(_int);
			break;
		case FLOAT :
			_float = std::atof(str.c_str());
			displayFloat(_float, str);
			break;
		case DOUBLE :
			_double = std::strtod(str.c_str(), NULL);
			displayDouble(_double, str);
			break;
		default : 
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: impossible" << std::endl;
			std::cout << "double: impossible" << std::endl;
	}
	return ;
}

void	ScalarConversion::displayChar(char _char)
{
	int		_int = static_cast<int>(_char);
	float	_float = static_cast<float>(_char);
	double	_double = static_cast<double>(_char);

	if (std::isgraph(_char))
		std::cout << "char: '" << _char << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << _int << std::endl;
	std::cout << "float: " << _float << ".0f" << std::endl;
	std::cout << "double: " << _double << ".0" <<std::endl;
}

void	ScalarConversion::displayInt(int _int)
{
	char	_char = static_cast<char>(_int);
	float	_float = static_cast<float>(_int);
	double	_double = static_cast<double>(_int);

	if (std::isgraph(_char) && _int < 256)
		std::cout << "char: '" << _char << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << _int << std::endl;
	std::cout << "float: " << _float << ".0f" << std::endl;
	std::cout << "double: " << _double << ".0" << std::endl;
}

void	ScalarConversion::displayFloat(float _float, std::string str)
{
	char	_char = static_cast<char>(_float);
	int		_int = static_cast<int>(_float);
	double	_double = static_cast<double>(_float);

	if (std::isgraph(_char))
		std::cout << "char: '" << _char << "'" << std::endl;
	else if (str == "-inff" || str == "+inff" || str == "nanf")
		std::cout << "char: impossible" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	if (str == "-inff" || str == "+inff" || str == "nanf")
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << _int << std::endl;
	int i = 2;
	while (str[str.size() - i] != '.')
	{
		if (str[str.size() - i] != '.' && str[str.size() - i] != '0')
		{
			std::cout << "float: " << _float << "f" << std::endl;
			std::cout << "double: " << _double << std::endl;
			return ;
		}
		i++;
	}
	std::cout << "float: " << _float << ".0f" << std::endl;
	std::cout << "double: " << _double << ".0" << std::endl;
}

void	ScalarConversion::displayDouble(double _double, std::string str)
{
	char	_char = static_cast<char>(_double);
	float	_float = static_cast<float>(_double);
	int		_int = static_cast<int>(_double);
	
	if (std::isgraph(_char))
		std::cout << "char: " << _char << std::endl;
	else if (str == "-inf" || str == "+inf" || str == "nan")
		std::cout << "char: impossible" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	if (str == "-inf" || str == "+inf" || str == "nan")
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << _int << std::endl;
	int i = 1;
	while (str[str.size() - i] != '.')
	{
		if (str[str.size() - i] != '.' && str[str.size() - i] != '0')
		{
			std::cout << "float: " << _float << "f" << std::endl;
			std::cout << "double: " << _double << std::endl;
			return ;
		}
		i++;
	}
	std::cout << "float: " << _float << ".0f" << std::endl;
	std::cout << "double: " << _double << ".0" << std::endl;
}
