/*
Khoa Dang Do
Dr. Arun Ravindran
ECGR 2104 - 01
22 March 2017
*/

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Polynomial
{
	private:
		double x;
		int n;
		int* a;
		
	public:
		Polynomial ();		//default constructor x,a = 0
		Polynomial (double xVal, int nVal);	
		void inputCoefficients ();		//a1=1, a2=2...
		Polynomial (const Polynomial &copy);		//copy constructor
		friend ostream&  operator <<(ostream& outputStream, const Polynomial& function);	//overload <<
		Polynomial& operator =(const Polynomial& rtSide); 		//= copy assignment
		~Polynomial ();		//destructor
};

Polynomial::Polynomial ()
{
	x = 0;
	n = 0;
	a = new int [n];
	
	for (int count = 0; count <= n; count++)		//recspective a = 0
	{
		a[count] = 0;
	}
}

Polynomial::Polynomial (double xVal, int nVal)
{
	x = xVal;
	n = nVal;
	a = new int [n];
	
	for (int count = 0; count <= n; count++)		//respective a = 0
	{
		a[count] = 0;
	}
}

void Polynomial::inputCoefficients ()
{
	for (int count = 0; count <= n; count++)
		{
			a[count] = count; 		//a = respective index
		}
}

Polynomial::Polynomial (const Polynomial &copy)
{
	x = copy.x;
	n = copy.n;
	a = new int [n];
	
	for (int count = 0; count <= n; count++)
	{
		a[count] = copy.a[count];
	}
}

Polynomial::~Polynomial()
{
	delete [] a;
	cout << "Destroying polynomial" << endl;
}

Polynomial& Polynomial::operator =(const Polynomial& rtSide)
{
	if (this == &rtSide)
	{
		return *this;
	}
	else
	{
		x = rtSide.x;
		n = rtSide.n;
		delete [] a;
		a = new int [n];
		
		for (int count = 0; count <= n; count++)
			a[count] = rtSide.a[count];

		return  *this;
	}
}

ostream&  operator <<(ostream& outputStream, const Polynomial& function)
{
	double s = 0;
	
	for (int count = 0; count <= function.n; count++)
	{
		s = s + function.a[count] * pow(function.x,count); 		// include cmath library
	}
	outputStream <<  s;		//should print 1.375, checked with calculator
	
	return outputStream;
}

int main ()
{
    Polynomial p1(0.5,3), p2(-1.0,5), p3; 
    p1.inputCoefficients(); // Set the coefficient of polynomial p1
    p2.inputCoefficients(); // Set the coefficient of polynomial p2
    cout << "Polynomial p1 evaluates to " << p1 << endl;
    cout << "Polynomial p2 evaluates to " << p2 << endl;
    Polynomial p4(p1); // Copy constructor for p4 
    p3 = p1; // Copy assignment operator
    cout << "Polynomial p3 evaluates to " << p3 << endl;
    cout << "Polynomial p4 evaluates to " << p4 << endl;
    return 0;
}
