#include "BitcoinExchange.hpp"

	// check if argv[1] is a file
	// if not, throw exception
	// if (std::ifstream(path))
	// 	std::cout << "File exist" << std::endl;
	// else
	// 	std::cout << "File doesn't exist" << std::endl;
	// if (std::ofstream(path))
	// 	std::cout << "File exist" << std::endl;
	// else
	// 	std::cout << "File doesn't exist" << std::endl;


	// open and parse file
	// check all lines for respect format : DATE | VALEUR
	// the date format is : annee-mois-jour
	// the valeur formt is : float or unsigned int between 0 and 1000
	// if not, throw exception
	// else, store in a map of std::string and float

	// open file with name on argv[1]
	// read file line by line
	// if date == map(date)
	// 	print map[date] && map[valeur] * value
	// else if (npos)
	// 	find map[date] la plus proche dans le passe (if 2019-12-10 bot find use 2019-12-09)

	// if negative number 
	// 	std::cout << "Error: not a positive number." << std::endl;
	// if unavailable > 1000
	// 	std::cout << "Error: too large number." << std::endl;
	// if date unavailable
	// 	std::cout << "Error: bad input => " << map[date] << std::endl;

int main(int argc, char **argv)
{
	(void)argv;
	if (argc != 2) {
		std::cout << "Error: could not open file." << std::endl;
		return (1);
	}
	BitcoinExchange exchange;
	if (exchange.getBaseStatus() == false)
		return (1);
	if (DEBUG)
		exchange.Print_Map(exchange.getDataMap());
	std::string path = argv[1];
	exchange.Search_File_Parser(path);
	return (0);
}