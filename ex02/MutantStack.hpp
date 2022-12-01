/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   MutantStack.hpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsinke <lsinke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/01 15:29:01 by lsinke        #+#    #+#                 */
/*   Updated: 2022/12/01 15:29:01 by lsinke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>

template<class T, class C = std::deque<T> >
class MutantStack: public std::stack<T, C> {
	public:
		typedef typename C::iterator	iterator;

		MutantStack(): std::stack<T, C>() {}
		MutantStack(const MutantStack<T, C> &other): std::stack<T, C>(other) {};
		virtual ~MutantStack() {}
		using std::stack<T, C>::operator=;

		iterator begin() throw() {
			return std::stack<T, C>::c.begin();
		}

		iterator end() throw() {
			return std::stack<T, C>::c.end();
		}
};
