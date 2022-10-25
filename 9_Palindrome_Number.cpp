#include <iostream>
#include <cmath>


using namespace std;


class Solution {
public:

    int* intDigitsToArray(int input) {
        
        int digits = (int) log10(input) + 1;
        int* output = new int[digits];

        for (int i = digits - 1; i >= 0; i--)
        {
            output[i] = input % 10;
            input = (int) input * 0.1;
        }
        
        return output;
    }

    bool isPalindrome(int x) {

        if (x > 0) {

            int digits = (int) log10(x) + 1;
            int digitsHalf = (int) digits * 0.5;

            int* intArray { intDigitsToArray(x) };

            for (int i = 0; i < digitsHalf; i++)
            {
                if (intArray[i] != intArray[digits - i - 1]) {
                    return false;
                }
            }

            delete[] intArray;

            return true;
        }
        else if (x == 0)
        {
            return true;
        }
        
        return false;
    }

    bool isPlanidromeIdeal(int x) {
        if(x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int revertedNumber = 0;
        while(x > revertedNumber) {
            revertedNumber = revertedNumber * 10 + x % 10;
            x = (int) x * 0.1;
        }

        return x == revertedNumber || x == (int) revertedNumber * 0.1;
    }
};


int main() {

    cout << boolalpha << Solution().isPalindrome(121);

    return 0;

}