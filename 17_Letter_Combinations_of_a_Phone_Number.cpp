#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;


class Solution 
{
public:
    unordered_map<char, vector<char>> digit_mapping
    {
        {'2', {'a', 'b', 'c'}},
        {'3', {'d', 'e', 'f'}},
        {'4', {'g', 'h', 'i'}},
        {'5', {'j', 'k', 'l'}},
        {'6', {'m', 'n', 'o'}},
        {'7', {'p', 'q', 'r', 's'}},
        {'8', {'t', 'u', 'v'}},
        {'9', {'w', 'x', 'y', 'z'}}
    };

    vector<string> letterCombinations(string digits) 
    {
        vector<string> result{};
        int remaining_digits{1};

        if (digits.size() == 0 || digit_mapping.count(digits[0]) == 0)
            return result;


        // Calculate total amount of digits
        for (int i{}; i < digits.size(); ++i)
        {
            if (i == 0)
                continue;
            remaining_digits *= digit_mapping[digits[i]].size();
        }

        
        // Seed in first digits        
        for (char c : digit_mapping[digits[0]])
        {
            for (int j{}; j < remaining_digits; ++j)
            {
                string s{c};
                result.push_back(s);
            }
        }

        if (digits.size() == 1)
            return result;
        else remaining_digits /= digit_mapping[digits[1]].size();
        
        // Append the rest
        for (int i{1}; i < digits.size(); i++)
        {
            if (remaining_digits == 0)
                return result;

            for (int j{}; j < result.size(); ++j)
            {
                char digit{digit_mapping[digits[i]][static_cast<int>(j / remaining_digits) % digit_mapping[digits[i]].size()]};
                result[j] += digit;
            }

            int next_size{static_cast<int>(digit_mapping[digits[i + 1]].size())};
            if (next_size == 0) next_size = 1;
            remaining_digits /= next_size;
        }
        
        return result;
    }
};



int main()
{
    vector<string> v {Solution{}.letterCombinations("23456789")};

    for(string s : v)
    {
        cout << s << '\n';
    }

    return 0;
}