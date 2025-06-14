#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <set>
#include <map>

#include "easyfind.hpp"  // Tu función template
#include "Except.hpp"    // Tu excepción personalizada

void testContainer(std::string name)
{
	std::cout << "\n--- Testing: " << name << " ---\n";
}

int main()
{
	// VECTOR
	testContainer("vector");
	std::vector<int> vec;
	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);
	try {
		std::vector<int>::iterator it = easyfind(vec, 20);
		std::cout << "Found in vector: " << *it << std::endl;
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	// LIST
	testContainer("list");
	std::list<int> lst;
	lst.push_back(5);
	lst.push_back(15);
	lst.push_back(25);
	try {
		std::list<int>::iterator it = easyfind(lst, 15);
		std::cout << "Found in list: " << *it << std::endl;
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	// DEQUE
	testContainer("deque");
	std::deque<int> deq;
	deq.push_back(7);
	deq.push_back(17);
	deq.push_back(27);
	try {
		std::deque<int>::iterator it = easyfind(deq, 17);
		std::cout << "Found in deque: " << *it << std::endl;
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	// SET
	testContainer("set");
	std::set<int> st;
	st.insert(3);
	st.insert(6);
	st.insert(9);
	try {
		std::set<int>::iterator it = easyfind(st, 6);
		std::cout << "Found in set: " << *it << std::endl;
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	// MAP (no usa easyfind)
	testContainer("map");
	std::map<int, std::string> myMap;
	myMap[1] = "one";
	myMap[2] = "two";
	myMap[3] = "three";

	std::map<int, std::string>::iterator mapIt = myMap.find(2);
	if (mapIt != myMap.end()) {
		std::cout << "Found in map: key = " << mapIt->first << ", value = " << mapIt->second << std::endl;
	} else {
		std::cout << "Key not found in map." << std::endl;
	}

	return 0;
}

