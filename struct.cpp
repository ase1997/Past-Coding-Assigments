#include <iostream>
#include <string>

using namespace std;

struct Account
{
	string name;
	double amount, annual_interest_rate;
};

void printAccount (Account& copyAccount);

int main ()
{
	Account my_account;
	cout << "Enter your name: ";
	getline (cin, my_account.name);
	cout << "Enter the amount you deposit: ";
	cin >> my_account.amount;
	cout << "Enter your annual interest rate (in decimals): ";
	cin >> my_account.annual_interest_rate;
	printAccount (my_account);
	
return 0;
}

void printAccount (Account& copyAccount)
{
	double interestEarned = copyAccount.amount * copyAccount.annual_interest_rate;
	cout << endl << endl << "Your name is " << copyAccount.name << "." << endl
		 << "Your deposit amount is " << copyAccount.amount << "." << endl
		 << "Your annual interest rate is " << copyAccount.annual_interest_rate << "." << endl
		 << "Your annual interest earned is " << interestEarned << ".";
}

