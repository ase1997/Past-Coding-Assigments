/* Reversing a string */

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

void reverseString(string in_str);

int main()
{
    string str1 = "Hello World!";
    string str2 = "racecar";
    string str3 = "2106AD";
    string str4 = "a man a plan a canal-panama";
    string str5 = " ";
    
    reverseString(str1);
    cout << endl;
    reverseString(str2);
    cout << endl;
    reverseString(str3);
    cout << endl;
    reverseString(str4);
    cout << endl;
    reverseString(str5);
    cout << endl;
    return 0;

}

void reverseString(string in_str)
{
	int start = 0, end = in_str.length(); 
	
	for (int end = in_str.length(); end >= start; end--)
	{
		cout << in_str[end];
	}
}
