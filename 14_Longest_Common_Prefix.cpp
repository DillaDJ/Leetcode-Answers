#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        string prefix = strs[0];

        for (int i{1}; i < strs.size(); i++)
        {
            if (strs[i] == "" || prefix == "") {
                return "";
            }

            for (int j{0}; j < strs[i].length(); j++) 
            {
                if (strs[i][j] != prefix[j]) 
                {
                    prefix = prefix.substr(0, j);
                    break;
                }

                if (j == strs[i].length() - 1)
                    prefix = prefix.substr(0, j + 1);
            }
        }

        return prefix;
    }
};


int main() {

    vector<string> in { "ab", "abb", "abbb" };

    cout << Solution().longestCommonPrefix(in) << endl;

    return 0;
}