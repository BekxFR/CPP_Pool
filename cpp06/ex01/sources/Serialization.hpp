/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chillion <chillion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:52:43 by chillion          #+#    #+#             */
/*   Updated: 2023/03/01 16:52:44 by chillion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
