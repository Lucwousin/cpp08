/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsinke <lsinke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/01 16:34:09 by lsinke        #+#    #+#                 */
/*   Updated: 2022/12/01 16:34:09 by lsinke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include "MutantStack.hpp"

static void testMutantStack() {
	std::cout << "Testing with MutantStack:\n";

	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << "top:\t" << mstack.top() << '\n';
	mstack.pop();
	std::cout << "size:\t" << mstack.size() << '\n';
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);

	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << '\n';
		++it;
	}
	std::stack<int> s(mstack);
	std::cout << '\n';
}

static void testVector() {
	std::cout << "Testing with vector:\n";

	std::vector<int> vec;
	vec.push_back(5);
	vec.push_back(17);
	std::cout << "top:\t" << vec.back() << '\n';
	vec.pop_back();
	std::cout << "size:\t" << vec.size() << '\n';
	vec.push_back(3);
	vec.push_back(5);
	vec.push_back(737);

	vec.push_back(0);
	std::vector<int>::iterator it = vec.begin();
	std::vector<int>::iterator ite = vec.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << '\n';
		++it;
	}
	std::stack<int, std::vector<int> > s(vec);
	std::cout << '\n';
}

static void testList() {
	std::cout << "Testing with list:\n";

	std::list<int> list;
	list.push_back(5);
	list.push_back(17);
	std::cout << "top:\t" << list.back() << '\n';
	list.pop_back();
	std::cout << "size:\t" << list.size() << '\n';
	list.push_back(3);
	list.push_back(5);
	list.push_back(737);

	list.push_back(0);
	std::list<int>::iterator it = list.begin();
	std::list<int>::iterator ite = list.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << '\n';
		++it;
	}
	std::stack<int, std::list<int> > s(list);
	std::cout << '\n';
}

int main()
{
	testMutantStack();
	testVector();
	testList();
}
