#include <iostream>
//#include "complex.h"

using namespace std;

class Complex
{
	private:
		double real;
		double imag;
	public:
		Complex ();
		Complex (double re, double im);
		Complex (double realPart);
		double getReal () const {return real;}
		double getImag () const {return imag;}
		friend Complex operator +(const Complex& num1, const Complex& num2);
		friend Complex operator -(const Complex& num1, const Complex& num2);
		friend Complex operator *(const Complex& num1, const Complex& num2);
		friend bool operator ==(const Complex& num1, const Complex& num2);
		friend ostream&  operator <<(ostream& outputStream, const Complex& num);
		friend istream&  operator >>(istream& inputStream, Complex& num);
};

int main ()
{
	Complex A(1,1), B(2,3), C, S, D;
	cout  << A << " + " << B << endl;
	S = A + B;
	cout << S << endl;
	cin >> C;
	D = A * C;
	cout << D;
	
	if (C == A) {cout << "They are equal" << endl;}
	else {cout << "They are not equal" << endl;}
	
	C = A * B;
	cout << C;
	
return 0;
}

Complex::Complex ()
{
	real = 0;
	imag = 0;
}

Complex::Complex (double re, double im)
{
	real = re;
	imag = im;
}

Complex::Complex (double realPart)
{
	real = realPart;
	imag = 0;
}

Complex operator +(const Complex& num1, const Complex& num2)
{
	double r_val1, im_val1;
	
	r_val1 = num1.getReal() + num2.getReal();
	im_val1 = num1.getImag() + num2.getImag();
	
	return Complex(r_val1, im_val1);
}

Complex operator -(const Complex& num1, const Complex& num2)
{
	double r_val2, im_val2;
	
	r_val2 = num1.getReal() - num2.getReal();
	im_val2 = num1.getImag() - num2.getImag();
	
	return Complex(r_val2, im_val2);
}

Complex operator *(const Complex& num1, const Complex& num2)
{
	double r_val3, im_val3;
	
	r_val3 = (num1.getReal() * num2.getReal()) - (num1.getImag() * num2.getImag());
	im_val3 = (num1.getReal() * num2.getImag()) + (num1.getImag() * num2.getReal());
	
	return Complex(r_val3, im_val3);
}


bool operator ==(const Complex& num1, const Complex& num2)
{
	return ((num1.getReal() == num2.getReal()) && (num1.getImag() == num2.getImag()));
}

ostream&  operator <<(ostream& outputStream, const Complex& num)
{
	double realOut, imagOut;
	
	realOut = num.real;
	imagOut = num.imag;
	
	outputStream << realOut << " " << "+" << " " << imagOut << "i";
	
	return outputStream;
}

istream&  operator >>(istream& inputStream, Complex& num)
{	
	string str;
	double re, im;
	
	getline (inputStream, str);
	int posPlus = str.find('+');
	int posI = str.find('i');
	re = stoi(str.substr(0,posPlus));
	im = stoi(str.substr(posPlus + 1, posI - posPlus - 1));
	num.real = re;
	num.imag = im;
//	inputStream >> num.real >> num.imag;
	
	return inputStream; 
}




