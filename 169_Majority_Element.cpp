#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
        int candidate{};
        int frequency{};

        for (int i = 0; i < nums.size(); i++)
        {
            if (frequency == 0)
                candidate = nums[i];

            if (nums[i] != candidate)
                --frequency;
            else
                ++frequency;
        }
        
        return candidate;
    }
};


int main()
{
    vector<int> a {1,2,2,1,1,1,2,2,1,1,2};
    cout << Solution{}.majorityElement(a);

    return 0;
}