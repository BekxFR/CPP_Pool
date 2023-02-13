#include "PhoneBook.hpp"

int main()
{
	std::string input;
	PhoneBook phonebook;

	while (true)
	{
		std::cout << "Please enter your command (Only accept ADD, SEARCH and EXIT)" << std::endl;
		if (!(std::getline(std::cin, input)))
			return (1);
		if (input == "ADD")
		{
			Contact contact;
			if (phonebook.push_contact(contact))
				return (1);
		}
		else if (input == "SEARCH")
		{
			if (!phonebook.displaylist(phonebook.contact_nbr()))
			{
				std::cout << "Enter the index of the contact you want to search: " << std::endl;
				while (true)
				{
					if (!(std::getline(std::cin, input)))
						return (1);
					if (std::atoi(input.c_str()) <= 8 && std::atoi(input.c_str()) >= 1)
					{
						phonebook.displaycontact(std::atoi(input.c_str()) - 1);
						break ;
					}
					else
						std::cout << "Wrong Index Value (range : 1 - 8)" << std::endl;
				}
			}
		}
		else if (input == "EXIT")
			break;
		else
			std::cout << "Invalid input. Try again." << std::endl;
	}
	return (0);
}