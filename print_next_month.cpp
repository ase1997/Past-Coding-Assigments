#include <iostream>
#include <string>

using namespace std;

class Month
{
	public:
		Month (string inM);
		Month (int m);
		Month ();
		void printMonth ();	
		Month NextMonth ();
	private:
		int month;	
};

int main ()
{
	Month m1("January"), m2 (2), m3;
	m1.printMonth ();
	m2.printMonth ();
	m3.printMonth ();
	Month m4 = m1.NextMonth ();
	m4.printMonth ();
	
return 0;

}

Month::Month (string inM)
{
	if (inM == "January") {month = 1;}
	else if (inM == "February") {month = 2;}
	else if (inM == "March") {month = 3;}
	else if (inM == "April") {month = 4;}
	else if (inM == "May") {month = 5;}
	else if (inM == "June") {month = 6;}
	else if (inM == "July") {month = 7;}
	else if (inM == "August") {month = 8;}
	else if (inM == "September") {month = 9;}
	else if (inM == "October") {month = 10;}
	else if (inM == "November") {month = 11;}
	else if (inM == "December") {month = 12;}
	else {cout << "Wrong input!" << endl; exit (-1);}
}

Month::Month (int m)
{
	if (m >= 1 && m <= 12)
	{month = m;}
	else {cout << "Wrong input! Setting default." << endl; month =1;}
}

Month::Month ()
{
	month = 1;
}

void Month::printMonth ()
{
	switch (month)
	{
		case 1: cout << "January" << endl; break;
		case 2: cout << "February" << endl; break;
		case 3: cout << "March" << endl; break;
		case 4: cout << "April" << endl; break;
		case 5: cout << "May" << endl; break;
		case 6: cout << "June" << endl; break;
		case 7: cout << "July" << endl; break;
		case 8: cout << "August" << endl; break;
		case 9: cout << "September" << endl; break;
		case 10: cout << "October" << endl; break;
		case 11: cout << "November" << endl; break;
		case 12: cout << "December" << endl; break;
	}
}

Month Month::NextMonth()
{
	int next_month = month + 1;
	return Month (next_month);
}

// the above =
 /* int Month 
 
 */
















