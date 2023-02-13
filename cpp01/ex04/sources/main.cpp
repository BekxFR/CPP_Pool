#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <string>

void replace_in_file(const char *filename, const std::string &s1, const std::string &s2)
{
	std::ifstream in_file(filename);
	try
	{
		if (in_file.fail())
			return (std::cerr << "Error : " << std::strerror(errno) << std::endl, (void) 1);
		std::string file_content((std::istreambuf_iterator<char>(in_file)), (std::istreambuf_iterator<char>()));
		// std::cout << "TEST" << std::endl;
		// in_file.close();

		std::string result;
		size_t pos = 0;
		size_t start = 0;
		while((pos = file_content.find(s1, start)) != std::string::npos)
		{
			result.append(file_content, start, pos - start);
			result.append(s2);
			start = pos + s1.length();
		}
		result.append(file_content, start, pos - start);
		char new_name[strlen(filename) + strlen(".replace") + 1];
		if(!strcpy(new_name, filename) || !strcat(new_name, ".replace"))
			return (std::cerr << "Error : " << std::strerror(errno) << std::endl, (void) 1);
		std::ofstream out_file(new_name);
		if (out_file.fail())
			return (std::cerr << "Error : " << std::strerror(errno) << std::endl, (void) 1);
		if (out_file.is_open())
		{
			out_file << result;
			// out_file.close();
		}
		return ((void) 0);
	}
	catch(const std::exception &exc)
	{
		// std::cerr << "Error : " << exc.what() << std::endl;
		std::cerr << "Error 1 : " << std::strerror(errno) << std::endl;
	}
	
	return ((void) 1);
}

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Wrong number of arguments - Need 3 args (Filename, string research and string for replace)" << std::endl;
		return (0);
	}
	std::string filename = argv[1];
	std::string researched = argv[2];
	std::string replace = argv[3];

	if(researched.length() < 1 || replace.length() < 1)
	{
		std::cout << "Researched or Replace string is empty" << std::endl;
		return (1);
	}
	const char *charname = &*filename.data();
	replace_in_file(charname, researched, replace);
	return (0);
}