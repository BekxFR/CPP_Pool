
#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	std::cout << "BitcoinExchange Default Constructor called" << std::endl;
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &obj)
{
	*this = obj;
}

BitcoinExchange::~BitcoinExchange()
{
	std::cout << "BitcoinExchange Destructor called" << std::endl;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &obj)
{
	(void)obj;
	std::cout << "BitcoinExchange Copy assignment operator called" << std::endl;
	return *this;
}

// BitcoinExchange::BitcoinExchange(const std::string& file)
// {
// 	std::cout << "BitcoinExchange Overload Constructor called" << std::endl;
// }

// void	BitcoinExchange::Print() const
// {
// 	std::cout << "BitcoinExchange print() called" << std::endl;
// }

// void	BitcoinExchange::Print(const std::string& date) const
// {
// 	std::cout << "BitcoinExchange print() called" << std::endl;
// }

// void	BitcoinExchange::Parse(const std::string& file)
// {

// }

#include <string>
#include <iostream>
#include <stdexcept>

// function for change std::string to float 
float	Change_String_To_Float(const std::string& str)
{
	int		i = 0;
	float	res = 0;
	float	decimal = 0.1;
	while (str[i] != '.' && str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return	(1);
		res = res * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] == '\0')
	{
		return (res);
	}
	i++;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return	(1);
		res += (str[i] - '0') * decimal;
		decimal *= 0.1;
		i++;
	}
	return (res);
}

int BitcoinExchange::Check_Data_Value(const std::string& valeur)
{
	float value = 0;
	value = Change_String_To_Float(valeur);
	if ((int)value < 0 || (int)value > INT_MAX)
		return (1);
	return (0);
}

int	BitcoinExchange::Check_Date(const std::string& date)
{
	std::string	year;
	std::string	month;
	std::string	day;
	int			count = 0;
	long int len = date.length();
	if (len != 10)
		return (1);
	for (int i = 0; i < (int)date.length(); i++)
	{
		if (i != 0 && date[i] == '-')
			count++;
		else if (date[i] < '0' || date[i] > '9')
			return (1);
		else if (count == 0)
			year += date[i];
		else if (count == 1)
			month += date[i];
		else if (count == 2)
			day += date[i];
	}
	if (year.length() != 4 || month.length() != 2 || day.length() != 2)
		return (1);
	int value = atoi(year.c_str());
	if (value <= 0 || value > 2023)
		return (1);
	value = atoi(month.c_str());
	if (value <= 0 || value > 12)
		return (1);
	value = atoi(day.c_str());
	if (value <= 0 || value > 31)
		return (1);
	return (0);
}

void	BitcoinExchange::Print_Map(std::map<std::string, float> mymap)
{
	for (std::map<std::string, float>::iterator it = mymap.begin(); it != mymap.end(); ++it)
	{
		 std::cout << "Date: " << it->first << " | value = " << it->second << "." << std::endl;
	}
}

int	BitcoinExchange::Parse_Line_Value(const std::string& line)
{
	std::istringstream str(line);
	int count = 0;
	std::string word;
	std::string tmp;

	while(std::getline(str, word, ','))
	{
		if (count == 2)
			return (1);
		if (count == 0)
		{
			tmp = word;
			if (this->Check_Date(word) == 1)
				return (1);
		}
		if (count == 1 && this->Check_Data_Value(word) == 1)
			return (1);
		else
			this->_data[tmp] = Change_String_To_Float(word);
		count++;
	}
	if (count != 2)
		return (1);
	return (0);
}

int	BitcoinExchange::Database_File_Parser(const std::string& filename)
{
	std::ifstream file(filename.c_str());
	if (!file.is_open()) {
		std::cerr << "Error: could not open file." << std::endl;
		return (1);
	}
	std::string			line;
	std::getline(file, line);
	if(file.eof())
		return (1);
	while (std::getline(file, line)) {
		if (this->Parse_Line_Value(line))
		{
			std::cerr << "Error: Wrong value find on Database file." << std::endl;
			return (1);
		}
	}
	return (0);
}

int	BitcoinExchange::Pre_Search_File_Parser(const std::string& filename)
{
	std::ifstream file(filename.c_str());
	if (!file.is_open()) {
		std::cerr << "Error: could not open file." << std::endl;
		return (1);
	}
	std::string			line;
	std::string			word;
	int					count = 0;
	while (std::getline(file, line)) {
		std::istringstream str(line);
		while(str >> word)
		{
			if (count == 3)
				return (1);
			if (str.fail() || !str.eof())
				return (1);
			if (count == 0 && Check_Date(word) == 1)
				return (1);
			if (count == 1 && word != "|")
				return (1);
			if (count == 2 && Check_Data_Value(word) == 1)
				return (1);
			count++;
		}
	}
	if (count != 3)
		return (1);
	return (0);
}

void	BitcoinExchange::Search_File_Parser(const std::string& filename)
{
	std::ifstream file(filename.c_str());
	if (!file.is_open()) {
		std::cerr << "Error: could not open file." << std::endl;
		return ;
	}
	std::string			line;
	std::string			word;
	std::string			tmp;
	int					count = 0;
	std::getline(file, line);
	while (std::getline(file, line)) {
		std::istringstream str(line);
		count = 0;
		while(str >> word)
		{
			if (count == 3)
				break ;
			if (count == 0 && Check_Date(word) == 1)
				std::cout << "Error: bad input => " << word << std::endl;
			if (count == 2)
				// check value;
			
			count++;
		}
	}
	// file.close();
}