#include "Contact.hpp"

Contact::Contact()
{}

Contact::~Contact()
{}

std::string new_getline()
{
	std::string input;

	while (input.length() < 1)
	{
		if (!(std::getline(std::cin, input)))
			return (NULL);
	}
	return(input);
}

int	Contact::add_new(Contact *contact)
{
	std::string input;

	std::cout << "Enter First Name : ";
	while (input.length() < 1)
	{
		if (!(std::getline(std::cin, input)))
			return (1);
	}
	contact->first_name = input;
	input.erase();
	std::cout << "Enter Last Name : ";
	while (input.length() < 1)
	{
		input.erase();
		if (!(std::getline(std::cin, input)))
			return (1);
	}
	contact->last_name = input;
	input.erase();
	std::cout << "Enter Nickname : ";
	while (input.length() < 1)
	{
		input.erase();
		if (!(std::getline(std::cin, input)))
			return (1);
	}
	contact->nickname = input;
	input.erase();
	std::cout << "Enter Phone Number : ";
	while (input.length() < 1)
	{
		input.erase();
		if (!(std::getline(std::cin, input)))
			return (1);
	}
	contact->phone_number = input;
	input.erase();
	std::cout << "Enter Darkest Secret : ";
	while (input.length() < 1)
	{
		input.erase();
		if (!(std::getline(std::cin, input)))
			return (1);
	}
	contact->darkest_secret = input;
	return (0);
}

void	Contact::show_contact() const
{
	std::cout << "###########################################" << std::endl;
	std::cout << "First name: " << first_name << std::endl;
	std::cout << "Last name: "<< last_name << std::endl;
	std::cout << "Nick name: "<< nickname << std::endl;
	std::cout << "Phone number: "<< phone_number << std::endl;
	std::cout << "Darkest secret: "<< darkest_secret << std::endl;
	std::cout << "###########################################" << std::endl;
}

void	Contact::list_contact(int i) const
{
	std::cout << std::right << std::setw(10) << (i + 1) << "|";
	if (first_name.size() > 10)
		std::cout << std::right << std::setw(9) << first_name.substr(0, 9) << "." << "|";
	else
		std::cout << std::right << std::setw(10) << first_name.substr(0, 10) << "|";
	if (last_name.size() > 10)
		std::cout << std::right << std::setw(9) << last_name.substr(0, 9) << "." << "|";
	else
		std::cout << std::right << std::setw(10) << last_name.substr(0, 10) << "|";
	if (nickname.size() > 10)
		std::cout << std::right << std::setw(9) << nickname.substr(0, 9) << "." << "#" << std::endl;
	else
		std::cout << std::right << std::setw(10) << nickname.substr(0, 10) <<"#" << std::endl;
	
}
