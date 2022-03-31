/*
Khoa Dang Do
Dr. Arun Ravindran
ECGR 2104 - 01
24 February 2017
*/

#include <iostream>

using namespace std;

const int NUM_ELEM = 5;
int* doubleArray(int *a);

int main ()
{
	int origArr[NUM_ELEM]; 
   
    for (int i = 0; i < NUM_ELEM; ++i)
        {origArr[i] = i;}
    cout << "Original array" << endl;
   
    for (int i = 0; i < NUM_ELEM; ++i)
       {cout << origArr[i]  << " ";}
    cout << endl;
   
    int *newArr = doubleArray(origArr);
    
	for (int i = 0; i < 2*NUM_ELEM; ++i)
        cout << newArr[i] << " ";
    cout << endl;
   
    delete [] newArr;

return 0;
}

int* doubleArray(int *a) 
{
    int* expand = new int [NUM_ELEM * 2];
    
    for (int count1 = 0; count1 < NUM_ELEM; count1++)
    	expand[count1] = a[count1];
    	
    for (int count2 = NUM_ELEM; count2 < NUM_ELEM*2; count2++)
    	expand[count2] = 0;
    	
    return expand;
}

