/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Span.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsinke <lsinke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/01 14:38:25 by lsinke        #+#    #+#                 */
/*   Updated: 2022/12/01 14:38:25 by lsinke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <set>
#include <stdexcept>

class Span {
	private:
		Span();
		Span &operator=(const Span &rhs);

		const unsigned int _capacity;
		std::multiset<int> _set;

	public:
		Span(const Span &other);
		explicit Span(unsigned int n);
		virtual ~Span();

		void addNumber(int n);
		template<class II>
		void addRange(II begin, II end);

		int shortestSpan() const;
		int longestSpan() const;

		const std::multiset<int> &getSet() const; // go
};

template<class II>
void Span::addRange(II begin, II end) {
	const std::ptrdiff_t count = std::distance(begin, end);
	if (count < 0)
		throw std::range_error("You think the end should come before the beginning?\n");
	if ((size_t) count > _capacity - _set.size())
		throw std::range_error("Adding this many values would overflow!\n");

	_set.insert(begin, end);
}
