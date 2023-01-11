#include <vector>
#include <iostream>

using namespace std;


class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {    
        int sum{};
        int max_sum{INT32_MIN};

        for (int i : nums)
        {
            sum += i;

            max_sum = max(sum, max_sum);
            if (sum < 0)
                sum = 0;
        }

        return max_sum;
    }
};


int main()
{
    vector<int> v{-2, 1, -3, 4, -1, 2, 1, -5, 4};

    cout << Solution{}.maxSubArray(v);

    return 0;
}