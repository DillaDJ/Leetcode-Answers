#include <iostream>
#include <cmath>

using namespace std;


class Solution {
public:
    int myAtoi(string s) {

        int sign = 1;

        bool flagged = false;
        bool flag_impossible = false;
        int digits = 0;

        bool leading = true;
        int result = 0;


        for (int i = 0; i < s.length(); i++) {

            if (leading) {

                if (s[i] == ' ') {
                    continue;
                }
                else if (s[i] == '-' || s[i] == '+') {
                    sign = s[i] == '-' ? -1 : 1;
                    leading = false;
                    continue;
                }
                else {
                    leading = false;
                }
            }

            
            bool is_ascii_digit = s[i] > 47 && s[i] < 58;

            if (is_ascii_digit && digits < 10) {

                int ascii_as_int = int(s[i]) - 48;

                // Skip leading 0s
                if (result == 0 && ascii_as_int == 0) {
                    continue;
                }

                // Flag if possible overflow
                if (!flagged && !flag_impossible) {

                    int range_digit = int(INT_MAX * pow(.1, 9 - digits)) % 10;

                    if (ascii_as_int > range_digit) {
                        flagged = true;
                    }
                    else if (ascii_as_int < range_digit) {
                        flag_impossible = true;
                    }
                
                }
                
                if (!flagged || (flagged && digits < 9)) {
                    result *= 10;
                    result += ascii_as_int;
                }
                
            }
            else if(!is_ascii_digit || digits > 10) {
                
                break;
            
            }
            digits++;

        }

        // Check for overflows        
        if ((flagged && digits == 10) || digits > 10) {
            if (sign == 1) {
                return INT_MAX;
            } else {
                return INT_MIN;
            }
        }

        return sign * result;
    }
};


int main() {

    cout << Solution().myAtoi("-2147483645") << endl;

    return 0;

}