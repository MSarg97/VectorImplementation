#include <iostream>
#include "Account.h"

Account::Account(double amount)
{
	// If the amount has negative value, assign to it 0 and print an error message,
	// else assign the amount to the balance
	if (amount < 0.0)
	{
		balance = 0.0;
		std::cout << "Initial balance is invalid, 0.0 is assigned to the balance!\n\n";
	}
	else
		balance = amount;
}

Account& Account::operator=(const Account& obj) 
{ 
	// If the same object is in both left and right sides of the assignment operator,
	// an error message is printed, else the balance value of the right side object is assigned
	// to the balance of the left side object
	if (&obj == this)
		std::cout << "\nSelf assignment error!\n";
	else
		balance = obj.balance; 

	return *this;
}

bool Account::debit(double amount)
{
	// If the amount is bigger, than the current balance, print an error message, else withdraw it 
	if (amount > balance)
	{
		std::cout << "\n\nDebit amount exceeds account's current balance!\n";
		return false;
	}
	else
		balance -= amount;

	return true;
}

std::ostream& operator<<(std::ostream& print, const Account& obj)
{
	print << "Balance: " << obj.balance;
	return print;
}