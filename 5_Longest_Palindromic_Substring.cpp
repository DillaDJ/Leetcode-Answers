
#include <iostream>
#include <string>

using namespace std;
 

class Solution {
public:

    string longestPalindrome(string s) {

        int result_idx = 0; 
        int result_length = 0;
        
        if (s.length() == 0 || s.length() == 1) {
            return s;
        }

        for (int i = 0; i < s.length(); i++)
        {
            int window_start = i;
            int window_end = i;
            
            // Repeating letters
            while (window_end + 1 <= s.length() && s[i] == s[window_end + 1]) {
                window_end++;
                i = window_end;
            }

            if (window_end - window_start + 1 > result_length) {
                result_idx = window_start;
                result_length = window_end - window_start + 1;
            }

            // Expanding edges
            while (window_start >= 0 && window_end <= s.length()) {

                if (s[window_start] != s[window_end]) {
                    break;
                }

                if (window_end - window_start + 1 > result_length) {
                    result_idx = window_start;
                    result_length = window_end - window_start + 1;
                }

                window_start--;
                window_end++;
            }
        }

        return s.substr(result_idx, result_length);
    }
};



int main() {

    cout << Solution().longestPalindrome("bananas") << endl;
    
    return 0;
}