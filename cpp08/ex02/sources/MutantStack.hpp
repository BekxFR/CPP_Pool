#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <vector>
#include <iostream>

template<typename T>
class MutantStack : public std::stack<T>
{
	public:
		typedef typename std::stack<T>::container_type::iterator				iterator;
		typedef typename std::stack<T>::container_type::const_iterator			const_iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator		reverse_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator	const_reverse_iterator;

		MutantStack<T>();
		MutantStack<T>(const MutantStack<T> &obj);
		virtual ~MutantStack<T>();
		MutantStack<T> &operator=(MutantStack<T> const &obj);

		iterator				begin();
		iterator				end();
		const_iterator			cbegin() const;
		const_iterator			cend() const;
		reverse_iterator		rbegin();
		reverse_iterator		rend();
		const_reverse_iterator	crbegin() const;
		const_reverse_iterator	crend() const;
};


//MutantStack herite de la STL std::stack mais au lieu d'utiliser deque par default elle utilise un vecteur pour stocker les elements
// template<typename T>
// class MutantStack : public std::stack<T, std::vector<T> >
// {
// 	public:
// 		typedef typename std::stack<T, std::vector<T> >::container_type::iterator				iterator;
// 		typedef typename std::stack<T, std::vector<T> >::container_type::const_iterator			const_iterator;
// 		typedef typename std::stack<T, std::vector<T> >::container_type::reverse_iterator		reverse_iterator;
// 		typedef typename std::stack<T, std::vector<T> >::container_type::const_reverse_iterator	const_reverse_iterator;

// 		MutantStack<T>();
// 		MutantStack<T>(const MutantStack<T> &obj);
// 		virtual ~MutantStack<T>();
// 		MutantStack<T> &operator=(MutantStack<T> const &obj);

// 		iterator				begin();
// 		iterator				end();
// 		const_iterator			cbegin() const;
// 		const_iterator			cend() const;
// 		reverse_iterator		rbegin();
// 		reverse_iterator		rend();
// 		const_reverse_iterator	crbegin() const;
// 		const_reverse_iterator	crend() const;
// };

#include "MutantStack.tpp"

#endif
