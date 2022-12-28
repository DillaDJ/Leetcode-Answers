#include <iostream>
#include <map>

using namespace std;


class Solution {
    int nextPowers(int n) 
    {
        int sum = 0;
        
        while (n > 0) 
        {
            int d = n % 10;
            n = n / 10;
            
            sum += d * d;
        }

        return sum;
    }

public:
    bool isHappy(int n) {
        map<int, int> seen {};
        
        while (n != 1 && seen.count(n) == 0) {
            seen[n] = true;
            n = nextPowers(n);
        }

        return n == 1;
    }
};


int main()
{
    cout << Solution{}.isHappy(19) << endl;

    return 0;
}