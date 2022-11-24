#include <iostream>
#include <string>
#include <cctype>

using namespace std;


class Solution {
public:
    bool isPalindrome(string s) 
    {
        int i{};
        int j{static_cast<int>(s.length() - 1)};

        while (i < j)
        {
            if (!isalnum(s[i]))
            {
                ++i;
                continue;
            }
            
            if (!isalnum(s[j]))
            {
                --j;
                continue;
            }

            if (tolower(s[i]) != tolower(s[j]))
                return false;
            
            ++i;
            --j;
        }

        return true;
    }
};


int main()
{
    cout << Solution{}.isPalindrome("A man, a plan, a canal: Panama");

    return 0;
}