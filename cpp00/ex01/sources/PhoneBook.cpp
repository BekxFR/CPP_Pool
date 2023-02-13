
#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : index(0), nbr_of_contact(0)
{}

PhoneBook::~PhoneBook()
{}

int	PhoneBook::current_index() const
{
	return (index);
}

int	PhoneBook::contact_nbr() const
{
	return (nbr_of_contact);
}

int	PhoneBook::push_contact(Contact contact)
{
	if (index + 1 > 8)
		index = 0;
	if (contact.add_new(&_contact[index]))
		return (1);
	index++;
	if (nbr_of_contact < 8)
		nbr_of_contact++;
	return (0);
}

void PhoneBook::displaycontact(int i) const
{
	_contact[i].show_contact();
}

int PhoneBook::displaylist(int contact_nbr) const
{
	if (contact_nbr == 0)
	{
		std::cout << std::right << "Empty phone book at the moment" << std::endl;
		return (1);
	}
	std::cout << "#    Index#First Name# Last Name#  Nickname#" << std::endl;
	for (int i = 0; i < contact_nbr; i++)
	{
		_contact[i].list_contact(i);
	}
	std::cout << "############################################" << std::endl;
	return (0);
}