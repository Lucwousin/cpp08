/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsinke <lsinke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/01 15:26:19 by lsinke        #+#    #+#                 */
/*   Updated: 2022/12/01 15:26:19 by lsinke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "Span.hpp"

static void providedTests() {
	std::cout << "Provided tests:\n";
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << "shortest:\t" << sp.shortestSpan() << '\n';
	std::cout << "longest:\t" << sp.longestSpan() << '\n';
	std::cout << '\n';
}

static int randomVal() {
	return rand() % 1000000;
}

static void addRandomVals(Span &span, unsigned int count) {
	srand(1234567); // reproducible
	std::vector<int> tmp(count);
	std::generate_n(tmp.begin(), count, randomVal);
	span.addRange(tmp.begin(), tmp.end());
}

static void printInt(int n) {
	std::cout << n << '\t';
}

static void test(unsigned int count, bool printSet) {
	std::cout << "Testing " << count << " random values:\n";
	Span sp = Span(count);
	addRandomVals(sp, count);

	if (printSet) {
		std::cout << "Printing set!:\n";
		const std::multiset<int> &set = sp.getSet();
		std::for_each(set.begin(), set.end(), printInt);
		std::cout << '\n';
	}
	std::cout << "shortest:\t" << sp.shortestSpan() << '\n';
	std::cout << "longest:\t" << sp.longestSpan() << '\n';
	std::cout << '\n';
}

static void testOverflow() {
	std::cout << "Testing overflow exceptions\n";
	Span span(0);
	try {
		span.addNumber(69);
	} catch (std::exception &ex) {
		std::cout << ex.what();
	}
	try {
		std::vector<int> tvec(5);
		span.addRange(tvec.begin(), tvec.end());
	} catch (std::exception &ex) {
		std::cout << ex.what();
	}
	std::cout << '\n';
}

int main()
{
	providedTests();
	try {
		test(1, true);
	} catch (std::exception &e) {
		std::cout << e.what();
	}
	test(2, true);
	test(5, true);
	test(10, true);
	test(69000, false);

	testOverflow();
	return 0;
}
