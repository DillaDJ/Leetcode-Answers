#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;


class Solution 
{
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        unordered_map<string, vector<string>> matched_frequencies{};
        vector<vector<string>> out;

        for (int i{}; i < strs.size(); ++i)
        {
            unordered_map<char, int> frequency{};

            string sorted{ strs[i] };
            sort(sorted.begin(), sorted.end());
            
            matched_frequencies[sorted].push_back(strs[i]);
        }
        
        for (auto const& [key, val] : matched_frequencies)
        {
            out.push_back(val);
        }

        return out;
    }
};


int main()
{
    vector<string> in{ "a" };
    vector<vector<string>> v{Solution{}.groupAnagrams(in)};

    return 0;
}