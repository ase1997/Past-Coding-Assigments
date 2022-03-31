#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;
vector<vector<string>> findAnagrams(const vector<string>& dict);



vector<vector<string>> findAnagrams(const vector<string>& dict)
{

    // Your code here...
    
	unordered_map <string , vector <string >> sorted_S_A ;
	
	for (const string& s : dict ) 
	{
	// Sorts the string , uses it as a key , and then appends
	// the original string as another value into hash table.
		string sorted_s (s);
		sort( sorted_s.begin (), sorted_s.end ());
		sorted_S_A [ sorted_s ].emplace_back (s);
	}
	
	vector <vector <string >> anagram;
	
	for (const auto& p : sorted_S_A ) 
	{
		if (p.second.size () >= 2) 
		{ // Found anagrams .
			anagram.emplace_back (p.second);
		}
	}
	
	return anagram;
}
