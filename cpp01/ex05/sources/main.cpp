#include "Harl.hpp"

int	main()
{
	Harl harl;

	harl.complain("DEBUG");
	harl.complain("INFO");
	harl.complain("WARNING");
	harl.complain("ERROR");
	std::cout << "Harl Other Level" << std::endl;
	harl.complain("OTHER");

	return (0);
}