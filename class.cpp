#include <iostream>
#include <string>

using namespace std;

class Account
{
	public:
		string getName();
		double getAmount();
		double getInterestRate();
		void setName (string newName);
		void setAmount (double newAmount);
		void setInterestRate (double newInterest);
		void updateAmount (double time);
	
		
	private:	
		string name;
		double amount;
		double annual_interest_rate;
};

int main ()
{
	Account my_account;
	my_account.setName("Charlie Brown");
	my_account.setAmount(1000);
	my_account.setInterestRate(0.05);
	my_account.updateAmount(2.0);
	
	cout << my_account.getName() << endl;
	cout << my_account.getInterestRate() << endl;
	cout << my_account.getAmount() << endl;

return 0;
}

string Account::getName()
{
	return name;
}

double Account::getAmount()
{
	return amount;
}

double Account::getInterestRate()
{
	return annual_interest_rate;
}

void Account::setName (string newName)
{
	name = newName;
}

void Account::setInterestRate (double newInterest)
{
	annual_interest_rate = newInterest;
}

void Account::setAmount (double newAmount)
{
	amount = newAmount;
}


void Account::updateAmount (double time)
{
	
	amount += amount*annual_interest_rate*time;
}
	




