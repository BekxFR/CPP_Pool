#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
	public:

	PhoneBook();
	~PhoneBook();
	int		push_contact(Contact contact);
	int		displaylist(int nbr_contact) const;
	void	displaycontact(int index) const;
	int		current_index() const;
	int		contact_nbr() const;

	private:

	int index;
	int	nbr_of_contact;
	Contact _contact[8];
};

#endif