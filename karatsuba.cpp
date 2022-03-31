#include<iostream>

using namespace std;

int numDigits(int num);
int pow10(int n);



int karatsuba(int x, int y)
{
   int x_length = numDigits(x);
   int y_length = numDigits(y);

   int L = x_length > y_length ? x_length : y_length; // get the bigger length between x and y

   // if L is small then multiply two numbers x and y
   if (L < 10)
    {
       return x * y;
	}		

   L = (L/2) + (L%2); // divide and roud L up

   int multiply = pow10(L);

   int a = x/multiply;
   int b = x - (a * multiply);
   int d = y / multiply;
   int c = y - (d * L);

   int z0 = karatsuba(b, c);
   int z1 = karatsuba(a + b, c + d);
   int z2 = karatsuba(a, d);

	return z0 + ((z1 - z0 - z2) * multiply) + (z2 * (int)(pow10(2*L)));
}



int numDigits(int num)
{
   int count = 0;
   
   while (num != 0) 
   {
       count++;
       num /= 10;
   }
   
   return count;
}



int pow10(int n)
{
   int i = 1;
   int result = 1;
   
   while (i <= n)
	{
       result = result * 10;
   	}
   	
   return result;
}



int main() 
{
    cout << "7*6 = " << karatsuba(7, 6) << endl;
    cout << "15*15 = " << karatsuba(15, 15) << endl;
    cout << "6*13 = " << karatsuba(6, 13) << endl;
    cout << "51*49 = " << karatsuba(51, 49) << endl;
    cout << "111*111 = " << karatsuba(111, 111) << endl;
    cout << "5678*1234 = " << karatsuba(5678, 1234) << endl;
    cout << "345678*1 = " << karatsuba(12345678, 1) << endl;
    cout << "12345678*0 = " << karatsuba(12345678, 0) << endl;
    
    return 0;
}


