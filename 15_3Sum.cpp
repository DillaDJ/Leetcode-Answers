#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>


using namespace std;

class Solution 
{
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        // So all duplicates are adjacent
        sort(nums.begin(), nums.end());

        vector<std::vector<int>> result;
        int nums_size = nums.size();

        for (int i = 0; i < nums_size; ++i) {
            // Skip duplicates
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int target = -nums[i];

            int start = i + 1;
            int end = nums_size - 1;

            while (start < end) {
                int sum = nums[start] + nums[end];
                
                if (sum == target) 
                {
                    result.push_back({nums[i], nums[start], nums[end]});
                    
                    // Skip duplicates
                    while (start < end && nums[start] == nums[start + 1]) 
                        ++start;
                    
                    while (start < end && nums[end] == nums[end - 1]) 
                        --end;

                    ++start;
                    --end;
                } 
                else if (sum < target) ++start;
                else --end;
            }
        }

        return result;
    }
};


int main()
{
    vector<int> nums{-1, 0, 1, -4};

    vector<vector<int>> result{ Solution{}.threeSum(nums) };

    for (vector<int> v : result)
    {
        for (int i : v) 
        {
            cout << i << " ";
        }
        cout << "\n";
    }

    cout << endl;

    return 0;
}