/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsinke <lsinke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/01 06:30:30 by lsinke        #+#    #+#                 */
/*   Updated: 2022/12/01 06:30:30 by lsinke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include "easyfind.hpp"

static void testVec() {
	std::vector<int> c;
	c.push_back(1);
	c.push_back(2);
	c.push_back(42);
	c.push_back(3);
	c.push_back(4);
	c.push_back(5);
	c.push_back(42);

	std::vector<int>::iterator result = easyfind(c, 42);
	if (&*result != &c.at(2))
		std::cerr << "We didn't find the value where expected in vector?\n";
	result = easyfind(c, -1);
	if (result != c.end())
		std::cerr << "We found a non-existing value in vector\n";
}

static void testDeque() {
	std::deque<int> c;
	c.push_back(1);
	c.push_back(2);
	c.push_back(42);
	c.push_back(3);
	c.push_back(4);
	c.push_back(5);
	c.push_back(42);

	std::deque<int>::iterator result = easyfind(c, 42);
	if (&*result != &c.at(2))
		std::cerr << "We didn't find the value where expected in deque?\n";
	result = easyfind(c, -1);
	if (result != c.end())
		std::cerr << "We found a non-existing value in deque\n";
}

static void testList() {
	std::list<int> c;
	c.push_back(1);
	c.push_back(2);
	c.push_back(42);
	c.push_back(3);
	c.push_back(4);
	c.push_back(5);
	c.push_back(42);

	std::list<int>::iterator result = easyfind(c, 42);
	std::list<int>::iterator control = c.begin();
	control++; control++;
	if (result != control)
		std::cerr << "We didn't find the value where expected in list?\n";
	result = easyfind(c, -1);
	if (result != c.end())
		std::cerr << "We found a non-existing value in list\n";
}

int main() {
	testVec();
	testDeque();
	testList();
}
