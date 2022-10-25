#include <iostream>

#include <string>
#include <unordered_map>

using namespace std;


class Solution {
public:
    unordered_map<char, int> numerals {
        { 'I', 1 },
        { 'V', 5 },
        { 'X', 10 },
        { 'L', 50 },
        { 'C', 100 },
        { 'D', 500 },
        { 'M', 1000 },
    };

    int romanToInt(string s) {

        int s_size = s.length();

        int result = 0;

        for (int i = 0; i < s_size; i++)
        {
            int next_numeral = 0;
            int current_numeral = numerals[s[i]];
            
            if (i < s_size - 1) {
                next_numeral= numerals[s[i + 1]];
            }

            if (next_numeral > current_numeral) {
                result += next_numeral - current_numeral;
                i++;

                continue;
            }
            else {
                result += current_numeral;
            }
        }
        
        return result;
    }
};


int main() {
    Solution s = Solution();
    cout << s.romanToInt("MCMXCIV");

    return 0;
}
