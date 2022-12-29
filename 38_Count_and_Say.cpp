#include <iostream>
#include <string>


using namespace std;



class Solution 
{
public:
    string generateSay(string s)
    {
        string generated{};
        char current{s[0]};
        int amount{0};

        for (int i{}; i <= s.length(); ++i)
        {
            if (i == s.length() || s[i] != current)
            {
                generated += static_cast<char>('0' + amount);
                generated += current;
                
                if (i == s.length()) break;
                
                current = s[i];
                amount  = 0;
            }

            ++amount;
        }

        return generated;
    }

    string countAndSay(int n) 
    {
        string output{ "1" };

        for (int i{1}; i < n; ++i)
            output = generateSay(output);

        return output;
    }
};


int main()
{
    cout << Solution{}.countAndSay(4) << '\n';

    return 0;
}