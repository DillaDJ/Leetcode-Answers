#include <iostream>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) 
    {
        map<char, int> char_freq_map{};

        for (int i{}; i < s.length(); ++i)
        {
            if (char_freq_map.count(s[i]) == 0)
                char_freq_map[s[i]] = 1;
            else
                ++char_freq_map[s[i]];
        }

        for (int i{}; i < s.length(); ++i)
        {
            if (char_freq_map[s[i]] == 1)
                return i;
        }

        return -1;
    }
};


int main() 
{
    cout << Solution{}.firstUniqChar("loveleetcode") << endl;
 
    return 0;
}