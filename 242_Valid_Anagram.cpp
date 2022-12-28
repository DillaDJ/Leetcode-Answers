#include <iostream>
#include <algorithm>
#include <string>

using namespace std;


class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        if (s.length() != t.length()) return false;

        sort(s.begin(), s.begin());
        sort(t.begin(), t.end());

        for (int i = 0; i < s.length(); i++)
            if(s[i] != t[i]) return false;
                
        return true;
    }
};


int main() 
{
    cout << Solution{}.isAnagram("aa", "bb") << endl;
 
    return 0;
}