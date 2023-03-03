/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chillion <chillion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 11:32:01 by chillion          #+#    #+#             */
/*   Updated: 2023/03/03 11:39:25 by chillion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template<typename T>
std::size_t Array<T>::Array::size() const
{
	return (this->_size);
}

template<typename T>
Array<T>::Array::Array() : _array(NULL), _size(0)
{
	std::cout << "Array Default Constructor called" << std::endl;
}

template<typename T>
Array<T>::Array::Array(unsigned int n) : _array(NULL), _size(n)
{
	std::cout << "Array Overload Constructor called" << std::endl;
	if (n < 0)
		throw std::out_of_range("Tab size value unvailable !");
	this->_array = new T[n];
	for(unsigned int i = 0; i < n; ++i)
		this->_array[i] = 0;
}

template<>
Array<std::string>::Array::Array(unsigned int n) : _array(NULL), _size(n)
{
	std::cout << "Array Overload Constructor called" << std::endl;
	if (n <= 0)
		throw std::out_of_range("Tab size value unvailable !");
	this->_array = new std::string[n];
	for(unsigned int i = 0; i < n; ++i)
		this->_array[i] = "";
}

template<typename T>
Array<T>::Array::Array(Array const &obj) : _array(NULL), _size(0)
{
	std::cout << "Array Copy Constructor called" << std::endl;
	*this = obj;
}

template<typename T>
Array<T>::Array::~Array()
{
	if (this->_size >= 0)
		delete [] this->_array;
	std::cout << "Array Destructor called" << std::endl;
}

template<typename T>
Array<T> &Array<T>::Array::operator=(Array<T> const &obj)
{
	if (this == &obj)
		return (*this);
	if (this->_size > 0)
		delete [] this->_array;
	this->_array = new T[obj.size()];
	this->_size = obj.size();
	for (unsigned int i = 0; i < this->_size; i++)
		this->_array[i] = obj._array[i];
	std::cout << "Array Copy assignment operator called" << std::endl;
	return *this;
}

template<typename T>
T &Array<T>::Array::operator[](unsigned int idx)
{
	if (idx < 0 || this->_size <= idx)
		throw std::out_of_range("Index tab value unvailable !");
	return (this->_array[idx]);
}

// template<typename T>
// T &Array<T>::Array::operator[](unsigned int idx) const
// {
// 	if (idx < 0 || this->_size <= idx)
// 		throw std::out_of_range("Index tab value unvailable !");
// 	return (this->_array[idx]);
// }
