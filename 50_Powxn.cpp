#include <iostream>
#include <vector>

using namespace std;


class Solution 
{
public:
    double myPow(double x, int n) 
    {
        if (n == 0) return 1;
        
        bool neg{n < 0};
        n = abs(n);

        long int exp{};
        long int current_exp{1};
        double temp_result{neg ? 1 / x : x};
        double result{1};

        while (exp != n)
        {
            while ((current_exp + current_exp) + exp < n)
            {
                temp_result *= temp_result;
                current_exp = current_exp == 1 ? 2 : current_exp + current_exp;
            }
            
            while (exp + current_exp <= n)
            {
                exp += current_exp;
                result *= temp_result;
            }
        
            current_exp = 1;
            temp_result = neg ? 1 / x : x;
        }

        return result;
    }
};


int main()
{
    cout << Solution{}.myPow(0.86429, 18) << '\n';

    return 0;
}