/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sungho <Sungho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 16:51:26 by Sungho            #+#    #+#             */
/*   Updated: 2024/01/23 14:00:06 by Sungho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack() {};
		~MutantStack() {};
		MutantStack(const MutantStack& m) {*this = m;};
		MutantStack &operator=(const MutantStack& m) {if (this == &m) return (*this); *this = m; return (*this);};
		typedef typename MutantStack<T>::stack::container_type::iterator	iterator;
		typedef typename MutantStack<T>::stack::container_type::reverse_iterator	reverse_iterator;
		typedef typename MutantStack<T>::stack::container_type::const_iterator	const_iterator;
		typedef typename MutantStack<T>::stack::container_type::const_reverse_iterator const_reverse_iterator;
		iterator begin() {return this->c.begin();};
		iterator end() {return this->c.end();};
		reverse_iterator rbegin() {return this->c.rbegin();};
		reverse_iterator rend() {return this->c.rend();};
		const_iterator	cbegin() {return this->c.cbegin();};
		const_iterator	cend() {return this->c.cbegin();};
		const_reverse_iterator	crbegin() {return this->c.crbegin();};
		const_reverse_iterator	crend() {return this->c.crbegin();};
};

#endif