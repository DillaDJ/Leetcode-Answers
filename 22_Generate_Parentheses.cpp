#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;


class Solution 
{
public:
    void matchParenthesis(vector<string>& out, int l, int r, string str = "")
    {
        if (l == 0 && r == 0)
        {
            out.push_back(str);
            return;
        }
        
        if (l > 0)          matchParenthesis(out, l - 1, r, str + "(");
        if (r > 0 && l < r) matchParenthesis(out, l, r - 1, str + ")");
    }

    vector<string> generateParenthesis(int n) 
    {
        vector<string> result;
        matchParenthesis(result, n, n);
        return result;
    }

};


int main()
{
    vector<string> paren{Solution{}.generateParenthesis(4)};

    for (auto s : paren)
        cout << s << '\n';

    return 0;
}