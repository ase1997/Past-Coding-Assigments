#include <iostream>
#include <string>

using namespace std;

bool  isPalindrome(string x);

int main()
{
    string s1 = "racecar";
    string s2 = "antidisestablishmentarianism";
    if(isPalindrome(s1))
     cout << s1 << " is a palindrome" << endl;
    else
        cout << s1 << " is not a palindrome" << endl;
    if(isPalindrome(s2))
        cout << s2 << " is a palindrome" << endl;
    else
        cout << s2 << " is not a palindrome" << endl;
    return 0;
}

bool isPalindrome(string x)
{	
	if (x.length() <= 1);
		return true;
	
	return (x[0] == x[x.length()-1] && isPalindrome(x.substr(1, x.length()-2)));
}
