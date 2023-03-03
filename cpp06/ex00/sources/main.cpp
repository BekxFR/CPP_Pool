#include "ScalarConversion.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error : Scalar Conversion need one parameter !" << std::endl;
		return (1);
	}
	if (atol(argv[1]) > INT_MAX || atol(argv[1]) < INT_MIN)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return (1);
	}
	ScalarConversion::convert(argv[1]);
	
	return 0;
}