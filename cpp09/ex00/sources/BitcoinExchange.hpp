#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <limits.h>
#include <string>
#include <stdexcept>

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <exception>
#include <iostream>
#include <memory>
#include <cstring>

#include <regex>

# define DEBUG 0

class BitcoinExchange
{
	private:
		std::map<std::string, float>	_data;
		bool							_baseStatus;

	public:
		BitcoinExchange();
		BitcoinExchange(BitcoinExchange const &obj);
		~BitcoinExchange();
		BitcoinExchange &operator=(BitcoinExchange const &obj);

		void	Print_Map(std::map<std::string, float> mymap);

		bool		Database_File_Parser(const std::string& filename);
		int			Check_Data_Value(const std::string& valeur);
		int			Check_Final_Data_Value(const float& valeur);
		int			Check_Date(const std::string& date);
		int			Parse_Line_Value(const std::string& line);
		void		Search_File_Parser(const std::string& filename);
		int			Pre_Search_File_Parser(const std::string& filename);
		std::string	Close_Date(const std::string& date);

		std::map<std::string, float>	getDataMap() const { return _data; };
		bool							getBaseStatus() const { return _baseStatus; };

		int		Regex_Check_Data_Value(const std::string& value);
		int		Regex_Check_Date(const std::string& date);
		float	Stream_Change_String_To_Float(const std::string& str);
		float	Stof_Change_String_To_Float(const std::string& line);


};

float	Change_String_To_Float(const std::string& str);

class UnvailableFloatValue : public std::exception {
	public:
		UnvailableFloatValue(const char* message) : msg_(new char[36 + std::strlen(message)]) {
			std::strcpy(msg_, "Error: Wrong value find in file : ");
			std::strcat(msg_, message);
		}

		const char* what() const throw() {
			return msg_;
		}

		~UnvailableFloatValue() {
			delete[] msg_;
		}

	private:
		char* msg_;
};

#endif
