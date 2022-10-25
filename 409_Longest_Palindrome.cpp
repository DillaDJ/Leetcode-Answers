#include <iostream>
#include <string>
#include <map>


using namespace std;


class Solution {
public:
    int longestPalindrome(string s) {
        
        map<char, int> char_map {};

        for (char c : s) {
            char_map[c]++;
        }

        int result = 0;
        bool odd_present = false;

        for (auto const& [key, val] : char_map) {
            
            if(val % 2 == 0) {
                result += val;
            }
            else {
                result += val - 1;
                odd_present = true;
            }

        }
        
        return result + int(odd_present);
    }
};


int main() {
    cout << Solution().longestPalindrome("aaaaa");
    
    return 0;
}