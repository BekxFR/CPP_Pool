/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chillion <chillion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 18:02:24 by chillion          #+#    #+#             */
/*   Updated: 2023/03/03 18:02:38 by chillion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

template<typename T>
typename T::iterator easyfind(T &t, int const int_search)
{
	return (find(t.begin(), t.end(), int_search));
}
