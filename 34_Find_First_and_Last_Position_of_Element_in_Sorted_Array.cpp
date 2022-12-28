#include <vector>
#include <iostream>

using namespace std;


class Solution 
{
public:
    int binarySearchEdge(vector<int>& nums, int target, bool low)
    {
        int first{};
        int mid  {};
        int last {static_cast<int>(nums.size() - 1)};

        while (first <= last)
        {
            mid = (first + last) / 2;

            if (nums[mid] == target) 
            {
                if (low)
                {
                    if (mid - 1 < 0 || nums[mid - 1] != target)
                        return mid;
                    
                    last = mid - 1;
                    continue;
                }
                else
                {
                    if (mid + 1 >= nums.size() || nums[mid + 1] != target)
                        return mid;
                    
                    first = mid + 1;
                    continue;
                }
            }

            if (nums[mid] > target) last = mid - 1;
            else first = mid + 1;
        }

        return -1;
    }

    vector<int> searchRange(vector<int>& nums, int target) 
    {
        int low {binarySearchEdge(nums, target, true)};
        int high{binarySearchEdge(nums, target, false)};

        vector<int> result{low, high};
        return result;
    }
};


int main()
{
    vector<int> in{};
    vector<int> v {Solution{}.searchRange(in, 8)};

    for (int i : v)
    {
        cout << i << '\n';
    }


    return 0;
}