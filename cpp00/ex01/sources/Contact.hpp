#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>
#include <csignal>
#include <cstdlib>
#include <iomanip>

class Contact
{
	public:

	Contact();
	~Contact();
	int	add_new(Contact *contact);
	void	show_contact() const;
	void	list_contact(int i) const;

	private:

	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;
};

#endif