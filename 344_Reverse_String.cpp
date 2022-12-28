#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) 
    {
        int half{static_cast<int>(s.size() / 2)};

        for (int i {}; i < half; i++)
        {
            char temp{s[s.size() - i - 1]};
            s[s.size() - i - 1] = s[i];
            s[i] = temp;
        }
    }
};


int main()
{
    vector<char> a{ 's', 't', 'u', 'u', 'n' };
    Solution{}.reverseString(a);

    return 0;
}