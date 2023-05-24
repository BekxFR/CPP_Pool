
#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : _data(), _baseStatus(Database_File_Parser("../cpp_09/data.csv"))
{
	if (DEBUG == 1)
		std::cout << "BitcoinExchange Default Constructor called" << std::endl;
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &obj)
{
	*this = obj;
}

BitcoinExchange::~BitcoinExchange()
{
	if (DEBUG == 1)
		std::cout << "BitcoinExchange Destructor called" << std::endl;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &obj)
{
	if (this != &obj) {
		this->_data = obj.getDataMap();
		this->_baseStatus = obj.getBaseStatus();
	}
	if (DEBUG == 1)
		std::cout << "BitcoinExchange Copy assignment operator called" << std::endl;
	return *this;
}

bool isValidDate(int day, int month, int year)
{
	if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31) {
		return false;
	}
	if (month == 4 || month == 6 || month == 9 || month == 11) {
		if (day > 30) {
			return (false);
		}
	}
	else if (month == 2) {
		if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
			if (day > 29) {
				return (false);
			}
		}
		else {
			if (day > 28) {
				return (false);
			}
		}
	}
	return (true);
}

float	BitcoinExchange::Stream_Change_String_To_Float(const std::string& value)
{
	double tmp = 0.0;
	std::istringstream str(value);
	str >> tmp;
	// if (!(iss >> tmp))
	// 	throw UnvailableFloatValue(str.c_str());
	if (str.fail() || !str.eof())
		throw UnvailableFloatValue(value.c_str());
	return (tmp);
}

float	Change_String_To_Float(const std::string& str)
{
	int		i = 0;
	int		sign = 1;
	long	res = 0;
	float	res2 = 0;
	float	res3 = 0;
	float	decimal = 0.1;

	while (str[i] != '.' && str[i] != '\0')
	{
		if (str[i] == '+' || str[i] == '-')
		{
			if (str[i] == '-')
				sign *= -1;
		}
		else if (str[i] < '0' || str[i] > '9')
			throw (UnvailableFloatValue(str.c_str()));
		else
			res = res * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] == '\0')
	{
		return (res * sign);
	}
	i++;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return	(1);
		res2 += (str[i] - '0') * decimal;
		decimal *= 0.1;
		i++;
	}
	res3 = (float)res + res2;
	return (res3);
}

int BitcoinExchange::Check_Data_Value(const std::string& valeur)
{
	float value = 0;
	try 
	{
		value = Stream_Change_String_To_Float(valeur);
	}
	catch (UnvailableFloatValue &e)
	{
		std::cout << e.what() << std::endl;
	}
	if (static_cast<long int>(value) < 0 || static_cast<long int>(value) > INT_MAX)
		return (1);
	return (0);
}

int BitcoinExchange::Check_Final_Data_Value(const float& value)
{
	if (static_cast<long int>(value) < 0)
	{
		std::cout << "Error: not a positive number." << std::endl;
		return (1);
	}
	if (static_cast<long int>(value) > 1000)
	{
		std::cout << "Error: too large number." << std::endl;
		return (1);
		
	}
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
	int iyear = atoi(year.c_str());
	if (iyear <= 0 || iyear > 2023)
		return (1);
	int imonth = atoi(month.c_str());
	if (imonth <= 0 || imonth > 12)
		return (1);
	int iday = atoi(day.c_str());
	if (iday <= 0 || iday > 31)
		return (1);
	if (isValidDate(iday, imonth, iyear) == false)
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
		// if(str.eof()){
		// 	return (1);}
		if (count == 2)
			return (1);
		if (count == 0)
		{
			tmp = word;
			if (this->Check_Date(word) == 1)
				return (1);
		}
		else if (count == 1 && this->Check_Data_Value(word) == 1)
			return (1);
		else
		{
			try 
			{
				this->_data[tmp] = Stream_Change_String_To_Float(word);
				// this->_data[tmp] = Change_String_To_Float(word);
			}
			catch (UnvailableFloatValue &e)
			{
				break ;
			}
		}
		count++;
	}
	if (count != 2)
		return (1);
	return (0);
}

bool	BitcoinExchange::Database_File_Parser(const std::string& filename)
{
	std::ifstream file(filename.c_str());
	if (!file.is_open()) {
		std::cout << "Error: could not open file." << std::endl;
		return (true);
	}
	std::string	line;
	std::getline(file, line);
	// if(!file.eof())
	// 	return (1);
	while (std::getline(file, line)) {
		// if (!file.eof() && this->Parse_Line_Value(line))
		if (this->Parse_Line_Value(line))
		{
			;
			// std::cout << "Error: Database file is not correctly formated." << std::endl;
			// return (0);
		}
	}
	if (this->_data.empty())
	{
		std::cout << "Error: Database file is empty." << std::endl;
		return (false);
	}
	return (true);
}

int	BitcoinExchange::Pre_Search_File_Parser(const std::string& filename)
{
	std::ifstream file(filename.c_str());
	if (!file.is_open()) {
		std::cout << "Error: could not open file." << std::endl;
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

std::string	BitcoinExchange::Close_Date(const std::string& date)
{
	std::string tmp = "";

	if (this->_data.find(date) == this->_data.end())
	{
		std::map<std::string, float>::iterator it = this->_data.lower_bound(date);
		if ((tmp != date && it != this->_data.begin()) || (it == this->_data.end())) {
			it--;
		}
		if (it != this->_data.end())
			tmp = it->first;
		// for (std::map<std::string, float>::iterator it = this->_data.begin(); it != this->_data.end(); ++it)
		// {
		// 	if (it->first < date && it->first > tmp)
		// 	{
		// 		tmp = it->first;
		// 	}
		// }
		// if (tmp.size() <= 0)
		// 	tmp = this->_data.begin()->first;
	}
	return (tmp);
}

void	BitcoinExchange::Search_File_Parser(const std::string& filename)
{
	std::ifstream file(filename.c_str());
	if (!file.is_open()) {
		std::cout << "Error: could not open file." << std::endl;
		return ;
	}
	std::string			line;
	std::string			word;
	std::string			date;
	std::string			tmp;
	int					count = 0;
	double				value = 0;

	std::getline(file, line);
	while (std::getline(file, line)) {
		std::istringstream str(line);
		count = 0;
		while(str >> word)
		{
			if (count == 3){
				break ;}
			if (count == 0)
			{
				tmp = word;
				if (Check_Date(word) == 1)
				{
					std::cout << "Error: bad input => " << word << std::endl;
					break ;
				}
			}
			if (count == 2)
			{
				try 
				{
					// value = Stream_Change_String_To_Float(word);
					value = Change_String_To_Float(word);
				}
				catch (UnvailableFloatValue &e)
				{
					std::cout << e.what() << std::endl;
					break ;
				}
				if (Check_Final_Data_Value(value) == 1)
					break ;
				else
				{
					date = Close_Date(tmp);
					if (date.size() == 0)
						date = tmp;
					std::cout << tmp << " => " << word << " = " << (this->_data[date] * value) << std::endl;
				}
			}
			count++;
		}
	}
}

// float	BitcoinExchange::Stof_Change_String_To_Float(const std::string& line)
// {
// 	float value = 0;
// 	try 
// 	{
// 		value = std::stof(line);
// 	}
// 	catch (std::exception &e)
// 	{
// 		throw UnvailableFloatValue(line.c_str());
// 	}
// 	return (value);
// }

// int	BitcoinExchange::Regex_Check_Date(const std::string& date)
// {
// 	std::regex	regex_date("^[0-9]{4}-[0-9]{2}-[0-9]{2}$");

// 	if (std::regex_match(date, regex_date))
// 		return (0);
// 	return (1);
// }

// int	BitcoinExchange::Regex_Check_Data_Value(const std::string& value)
// {
// 	std::regex	regex_value("^[+-]?[0-9]+(\\.[0-9]+)?$");

// 	if (std::regex_match(value, regex_value))
// 		return (0);
// 	return (1);
// }