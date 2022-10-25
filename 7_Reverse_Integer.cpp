#include <iostream>
#include <cmath>

using namespace std;
 

class Solution {
public:
    const int cRange = 2147483647;
    const int cRangeNeg = -2147483648;

    
    int reverse(int x) {

        int sign = x < 0 ? -1 : 1;
        int range = sign == 1 ? INT_MAX : INT_MIN;

        bool flagged = false;
        bool flag_impossible = false;
        int digits = 0;

        int result = 0;

        
        while (x != 0 && digits < 10) {
            int input_last = x % 10;
            
            // Flag if possible overflow
            if (!flagged && !flag_impossible) {

                int range_digit = int(range * pow(.1, 9 - digits)) % 10;

                if (sign == 1) {
                    if (input_last > range_digit) {
                        flagged = true;
                    }
                    else if (input_last < range_digit) {
                        flag_impossible = true;
                    }
                }
                else {
                    if (input_last < range_digit) {
                        flagged = true;
                    }
                    else if (input_last > range_digit) {
                        flag_impossible = true;
                    }
                }
            }

            // Trim input by one digit
            x -= input_last;
            x *= 0.1;

            // Add digit to result if it won't overflow
            if (!flagged || (flagged && digits < 9)) {
                result *= 10;
                result += input_last;
            }

            digits++;
        }
        
        // If flagged and there are 10+ digits, an overflow occured
        if (flagged && digits > 9) {
            return 0;
        }

        // Return result if already negative
        if (sign == -1 && result < 0) {
            return result;
        }

        return sign * result;
    }
};



int main() {

    cout << Solution().reverse(563847412) << endl;
    
    return 0;
}