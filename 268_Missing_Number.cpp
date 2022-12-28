#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) 
    {
        int num{};

        for (int i = 0; i <= nums.size(); ++i)
        {
            if (i < nums.size()) num ^= nums[i];
            num ^= i;
        }

        return num;
    }
};


int main() 
{
    vector<int> v{0, 1, 2};
    cout << Solution{}.missingNumber(v) << endl;
 
    return 0;
}