#include <iostream>
#include <string>

int main(int argc, char **argv)
{
	std::string output;
	for (int i = 1; i < argc; i++)
	{
		std::string MyArgv(argv[i]);
		for (int len = 0; MyArgv[len]; len++)
			MyArgv[len] = toupper(MyArgv[len]);
		output += MyArgv;
	}
	if (output.empty()) 
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
		std::cout << output << std::endl;
	return (0);
}
