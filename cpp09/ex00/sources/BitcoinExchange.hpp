#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <limits.h>

class BitcoinExchange
{
	private:
		std::map<std::string, float> _data;
		std::map<std::string, float> _search;
		// std::map<std::string,std::pair<std::string,int> > _data;
	/* data */

	public:
		BitcoinExchange();
		// BitcoinExchange(const std::string& file);
		BitcoinExchange(BitcoinExchange const &obj);
		~BitcoinExchange();
		BitcoinExchange &operator=(BitcoinExchange const &obj);

		void	Print_Map(std::map<std::string, float> mymap);
		// void	Print() const;
		// void	Print(const std::string& date) const;
		// void	Print(const std::string& date, float value) const;
		// void	Print(const std::string& date, float value, float amount) const;
		// void	Print(const std::string& date, float value, float amount, float total) const;

		// void	Parse(const std::string& file);
		// void	Parse(const std::string& date, const std::string& value);
		// float 	Get(const std::string& date) const;
		// float 	Get(const std::string& date, float value) const;
		// float 	Get(const std::string& date, float value, float amount) const;
		// float 	Get(const std::string& date, float value, float amount, float total) const;


		int		Database_File_Parser(const std::string& filename);
		int		Check_Data_Value(const std::string& valeur);
		int		Check_Date(const std::string& date);
		int		Parse_Line_Value(const std::string& line);
		void	Search_File_Parser(const std::string& filename);
		int		Pre_Search_File_Parser(const std::string& filename);

		std::map<std::string, float>	Get_Data_Map() { return _data; };
		std::map<std::string, float>	Get_Search_Map() { return _search; };

};
float	Change_String_To_Float(const std::string& str);

#endif
