#include "Vector.h"
#include "Account.h"
#include <iostream>

int main()
{
	// Creating vector of 5 integers (build-in data type) with 16 default value 
	Vector<int> intVector(5, 16);

	// Pushing integers from 1 to 5 into the intVector
	for (int i = 0; i < 5; ++i)
		intVector.push_back(i + 1);
		
	// Printing intVector using overloaded subscript operator
	std::cout << "\nintVector:\n";
	for (int i = 0; i < intVector.size(); ++i)
		std::cout << intVector[i] << ' ';
	
	// Resizing intVector. It will consist of 15 elements and
	// added elements will be initialized with default value. 
	intVector.resize(15);

	// Printing intVector by using iterators
	std::cout << "\n\nintVector after resizing:\n";
	for (auto it = intVector.begin(); it != intVector.end(); ++it)
		std::cout << *it << ' ';


	// Creating constant vector of 5 integers with 8 default value 
	const Vector<int> constVector(5, 8);
	
	// This statements and calls are not allowed for constant vector
	// constVector.push_back(15);
	// constVector.pop_back();
	// constVector.at(2) = 25;
	// constVector[2] = 25;
	// constVector.resize(16);
	
	// Printing constVector by using at() function
	std::cout << "\n\nconstVector:\n";
	for (int i = 0; i < constVector.size(); ++i)
		std::cout << constVector.at(i) << ' ';

	// Printing cVector by using overloaded subscript operator
	std::cout << "\n\nconstVector:\n";
	for (int i = 0; i < constVector.size(); ++i)
		std::cout << constVector[i] << ' ';

	// Printing constVector by using iterators	
	std::cout << "\n\nconstVector:\n";
	for (auto it = constVector.cbegin(); it != constVector.cend(); ++it)
		std::cout << *it << ' ';

	// Printing first and last elements of constVector by reference
	std::cout << "\n\nFirst element of constVector: " << constVector.front();
	std::cout << "\nLast element of constVector: " << constVector.back();

	// Printing first and last elements of constVector by using iterators
	std::cout << "\n\nFirst element of constVector: " << *(constVector.cbegin());
	std::cout << "\nLast element of constVector: " << *(constVector.cend() - 1);

	
	// Creating intVector1 by copying intVector
	Vector<int> intVector1(intVector);

	// Printing intVector1 by using at() function
	std::cout << "\n\nintVector1:\n";
	for (int i = 0; i < intVector.size(); ++i)
		std::cout << intVector.at(i) << ' ';

	// Printing intVector1's size and capacity before and after calling shrink_to_fit function
	std::cout << "\n\nSize of intVector1: " << intVector1.size();
	std::cout << "\nCapacity of intVector1: " << intVector1.capacity();

	std::cout << "\n\nCalling shrink_to_fit() function";
	intVector1.shrink_to_fit();

	std::cout << "\n\nSize of intVector1: " << intVector1.size();
	std::cout << "\nCapacity of intVector1: " << intVector1.capacity();


	// Creating vector of 5 characters (build-in data type) with 'a' default value 
	Vector<char> charVector(5, 'a');

	// Pushing 10 'v' characters into charVector
	for (int i = 0; i < 10; ++i)
		charVector.push_back('v');

	// Printing charVector using overloaded subscript operator
	std::cout << "\n\ncharVector:\n";
	for (int i = 0; i < charVector.size(); ++i)
		std::cout << charVector[i] << ' ';

	// Printing first and last elements of charVector by reference
	std::cout << "\n\nFirst element of charVector: " << charVector.front();
	std::cout << "\nLast element of charVector: " << charVector.back();

	// Printing first and last elements of charVector by using iterators
	std::cout << "\n\nFirst element of charVector: " << *(charVector.begin());
	std::cout << "\nLast element of charVector: " << *(charVector.end() - 1);

	
	// Creating a vector of 5 Account (data type defined by user) elements
	Vector<Account> AccountVector(5);

	// Creating Account objects and passing different balance values
	Account ob1(23.5);
	Account ob2(8.25);
	Account ob3; //No argument is passed, so a default value (0.0) will be assigned to the balance
	Account ob4(1000.5);

	// Pushing Account objects into the AccountVector
	AccountVector.push_back(ob1);
	AccountVector.push_back(ob2);
	AccountVector.push_back(ob3);
	AccountVector.push_back(ob4);
	
	// Printing AccountVector's elements. Actually it prints balance values of each Account object,
	// that is pushed into the vector
	std::cout << "\n\nAccountVector:\n";
	for (int i = 0; i < AccountVector.size(); ++i)
		std::cout << AccountVector[i] << "\n";

	// If AccountVector is empty and there's nothing to pop, an appropriate message is printed.
	std::cout << "\nPopping elements of AccountVector:\n";
	for (int i = 0; i < 15; i++)
		AccountVector.pop_back();

	return 0;
} 