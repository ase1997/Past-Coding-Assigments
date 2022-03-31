/* Khoa Dang Do
   Dr. Arun Ravindran
   ECGR 2104 - 001
   02/22/2017 */

//--------------------------------------------------------------------------------------------------------------------------------------//

#include <iostream>
#include <string>

using namespace std;

//--------------------------------------------------------------------------------------------------------------------------------------//

class Rational
{
	private:
		// 3 private variables
		int numerator;
		int denominator;
		char slash = '/'; // assigns the divisor  to be "/" for easier use
	public:
		Rational (); // default constructor 0/1
		Rational (int num, int den); // constructor sets num/den val
		Rational (int top); // sets bottom = 1
		// friend function to overload operators
		friend Rational operator +(const Rational& num1, const Rational& num2);
		friend Rational operator -(const Rational& num1, const Rational& num2);
		friend Rational operator *(const Rational& num1, const Rational& num2);
		friend Rational operator /(const Rational& num1, const Rational& num2);
		friend bool operator ==(const Rational& num1, const Rational& num2);
		friend bool operator >=(const Rational& num1, const Rational& num2);
		friend bool operator <=(const Rational& num1, const Rational& num2);
		friend bool operator >(const Rational& num1, const Rational& num2);
		friend bool operator <(const Rational& num1, const Rational& num2);
		friend ostream&  operator <<(ostream& outputStream, const Rational& num);
		friend istream&  operator >>(istream& inputStream, Rational& num);
};

//--------------------------------------------------------------------------------------------------------------------------------------//

int main ()
{
	Rational n1(1,2), n2, n3;
	cout << n1 << endl;
	cin >> n2; // Input 2/3
	//cout << n2 << endl;
	cout << n1 + n2 << endl;
	cout << n1 - n2 << endl;
	cout << n1 * n2 << endl;
	cout << n1 / n2 << endl;

	if (n1 == n2)
		cout << "n1 equals n2" << endl;
	else if (n1 > n2)
		cout << n1 << " greater than " << n2 << endl;
	else
		cout << n1 << " less than " << n2 << endl;

	cin >> n3; // Input -1/3
	//cout << n3 << endl;
	
	if (n3 >= 0)
		cout << n3 << " is non-negative" << endl;
	else if (n3 <= 0)
		cout << n3 << " is non-positive" << endl;

return 0;
}

//--------------------------------------------------------------------------------------------------------------------------------------//

Rational::Rational ()
{
	numerator = 0;
	denominator = 1;
}

//--------------------------------------------------------------------------------------------------------------------------------------//

Rational::Rational (int num, int den)
{
	numerator = num;
	denominator = den;
}

//--------------------------------------------------------------------------------------------------------------------------------------//

Rational::Rational (int top)
{
	numerator = top;
	denominator = 1;
}

//--------------------------------------------------------------------------------------------------------------------------------------//

Rational operator +(const Rational& num1, const Rational& num2)
{
	int t1, b1;
	
	t1 = (num1.numerator * num2.denominator) + (num1.denominator * num2.numerator);
	b1 = num1.denominator * num2.denominator;
	
	return Rational(t1, b1);
}

//--------------------------------------------------------------------------------------------------------------------------------------//

Rational operator -(const Rational& num1, const Rational& num2)
{
	int t2, b2;
	
	t2 = (num1.numerator * num2.denominator) - (num1.denominator * num2.numerator);
	b2 = num1.denominator * num2.denominator;
	
	return Rational(t2, b2);
}

//--------------------------------------------------------------------------------------------------------------------------------------//

Rational operator *(const Rational& num1, const Rational& num2)
{
	int t3, b3;
	
	t3 = num1.numerator * num2.numerator;
	b3 = num1.denominator * num2.denominator;
	
	return Rational(t3, b3);
}

//--------------------------------------------------------------------------------------------------------------------------------------//

Rational operator /(const Rational& num1, const Rational& num2)
{
	int t4, b4;
	
	t4 = num1.numerator * num2.denominator;
	b4 = num1.denominator * num2.numerator;
	
	return Rational(t4, b4);
}

//--------------------------------------------------------------------------------------------------------------------------------------//

bool operator ==(const Rational& num1, const Rational& num2)
{
	return ((num1.numerator * num2.denominator) == (num1.denominator * num2.numerator));
}

//--------------------------------------------------------------------------------------------------------------------------------------//

bool operator >=(const Rational& num1, const Rational& num2)
{
	return ((num1.numerator * num2.denominator) >= (num1.denominator * num2.numerator));
}

//--------------------------------------------------------------------------------------------------------------------------------------//

bool operator <=(const Rational& num1, const Rational& num2)
{
	return ((num1.numerator * num2.denominator) <= (num1.denominator * num2.numerator));
}

//--------------------------------------------------------------------------------------------------------------------------------------//

bool operator >(const Rational& num1, const Rational& num2)
{
	return ((num1.numerator * num2.denominator) > (num1.denominator * num2.numerator));
}

//--------------------------------------------------------------------------------------------------------------------------------------//

bool operator <(const Rational& num1, const Rational& num2)
{
	return ((num1.numerator * num2.denominator) < (num1.denominator * num2.numerator));
}

//--------------------------------------------------------------------------------------------------------------------------------------//

ostream&  operator <<(ostream& outputStream, const Rational& num)

{	
	outputStream << num.numerator << num.slash << num.denominator;
	
	return outputStream;
}

//--------------------------------------------------------------------------------------------------------------------------------------//

istream&  operator >>(istream& inputStream, Rational& num)
{	
	inputStream >> num.numerator >> num.slash >> num.denominator;
	
	return inputStream;
}

//--------------------------------------------------------------------------------------------------------------------------------------//
