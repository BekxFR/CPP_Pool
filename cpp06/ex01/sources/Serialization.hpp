#ifndef SERIALIZATION_HPP
#define SERIALIZATION_HPP

#include <iostream>
#include <stdint.h>

struct Data
{
	std::string	str_value;
	int 		int_value;
	void		getValues() const;
};

class Serialization
{
	private:
		Serialization();
		Serialization(Serialization const &obj);
		~Serialization();
		Serialization &operator=(Serialization const &obj);

	public:
		static uintptr_t serialize(Data *ptr);
		static Data *deserialize(uintptr_t raw);
};

#endif
