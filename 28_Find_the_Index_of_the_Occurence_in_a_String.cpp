#include <string>
#include <iostream>

using namespace std;


class Solution 
{
public:
    int strStr(string haystack, string needle) 
    {
        if (haystack.length() < needle.length()) return -1;
    
        int first_letter_pos{0};
        int last_letter_pos {static_cast<int>(needle.length()) - 1};
    
        for (; last_letter_pos < haystack.length(); ++first_letter_pos, ++last_letter_pos)
        {
            bool match
            { 
                haystack[first_letter_pos] == needle[0] && 
                haystack[last_letter_pos] == needle[needle.length() - 1]
            };
            
            if (match)
            {
                int inner_first{first_letter_pos};
                int inner_last {last_letter_pos };
                int iterations{};

                while (match)
                {
                    if (inner_first >= inner_last) return first_letter_pos;
                
                    ++inner_first;
                    --inner_last;
                    ++iterations;

                    match = haystack[inner_first] == needle[iterations] && 
                            haystack[inner_last] == needle[needle.length() - 1 - iterations];
                }
            }
        }
        
        return -1;
    }
};


int main()
{
    cout << Solution{}.strStr("leetcode", "leeto") << '\n';

    return 0;
}