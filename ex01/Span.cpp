/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Span.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsinke <lsinke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/01 14:38:21 by lsinke        #+#    #+#                 */
/*   Updated: 2022/12/01 14:38:21 by lsinke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <numeric>
#include "Span.hpp"

Span::Span(): _capacity(0) {}

Span &Span::operator=(const Span &rhs) {
	if (this == &rhs)
		return *this;

	_set = rhs._set;
	return *this;
}

Span::Span(const Span &other): _capacity(other._capacity) {
	*this = other;
}

Span::Span(unsigned int n): _capacity(n) {}

Span::~Span() {}

void Span::addNumber(int n) {
	if (_set.size() == _capacity)
		throw std::range_error("This throws a spanner in the works.. We're already at capacity!\n");

	_set.insert(n);
}

int Span::shortestSpan() const {
	if (_set.size() <= 1)
		throw std::runtime_error("There's less than 2 values in the set, so there's no span!\n");
	if (_set.size() == 2)
		return *_set.rbegin() - *_set.begin();

	/*
	 * This function iterates the first and third iterator argument at the same time.
	 * It's return value is initialized to INT_MAX, and it subtracts the smaller value from
	 * the bigger one and checks if it's smaller than the return value. If yes, replace it!
	 */
	return std::inner_product(
			std::next(_set.begin()), std::prev(_set.end()), // iterator 1 start and end
			_set.begin(), // iterator 2 start
			INT32_MAX, // initial value
			std::min<int>, std::minus<int>()); // functions to call (will be like `rv = min(rv, *i1 - *i2)`)
}

int Span::longestSpan() const {
	if (_set.size() <= 1)
		throw std::runtime_error("There's less than 2 values in the set, so there's no span!\n");

	const int &min = *_set.begin();
	const int &max = *_set.rbegin();
	return max - min;
}

const std::multiset<int> &Span::getSet() const {
	return _set;
}
