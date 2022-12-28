#include <iostream>

using namespace std;


class Solution 
{
public:
    int divide(int dividend, int divisor) 
    {
        int sign{-1};
        if (dividend >= 0 == divisor > 0)
            sign = 1;
             
        if (dividend == INT32_MIN) dividend = INT32_MAX;
        else dividend = abs(dividend);
        
        divisor  = abs(divisor);
        
        if (divisor == 1 || divisor == -1) return sign * dividend;


        int quotient{};
        int sum{};

        int interval{divisor};  // Contains number we increase sum by (multiple of the divisor)
        int interval_amount{1}; // How many divisors make up the interval
        
                
        while (sum < dividend)
        {
            if (interval_amount == 1 && interval + sum > dividend) break;

            while (interval + interval + sum < dividend)
            {
                interval += interval;
                interval_amount += interval_amount;
            }

            quotient += interval_amount;
            sum += interval;
            
            interval = divisor;
            interval_amount = 1;
        }

        return sign * quotient;
    }
};


int main()
{
    cout << Solution{}.divide(-2147483648, -1) << '\n';

    return 0;
}