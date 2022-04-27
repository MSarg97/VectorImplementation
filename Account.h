#ifndef ACCOUNT_H
#define ACCOUNT_H

// An implementation of Account class, which allows the user to add an amount to the Account balance,
// or withdraw an amount from the balance
class Account
{
public:
	Account(double = 0.0); // Initializer constructor with default argument
	Account(const Account& obj) { balance = obj.balance; } // Copy constructor
	
	Account& operator=(const Account&); // Overloading assignment operator
	friend std::ostream& operator<<(std::ostream&, const Account&); // Overloading << operator 

	void credit(double amount) { balance += amount; } // Add an amount to the balance
	bool debit(double); // Withdraw an amount from the Account
	double getBalance() { return balance; } // Return the balance
	
private:
	double balance; // Balance of the current Account
};

#endif // !ACCOUNT_H