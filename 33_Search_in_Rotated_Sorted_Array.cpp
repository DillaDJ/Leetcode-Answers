#include <vector>
#include <iostream>

using namespace std;


class Solution 
{
public:
    int search(vector<int>& nums, int target) 
    {
        int high{static_cast<int>(nums.size() - 1)};
        int mid {};
        int low {};
    
        while (low < high)
        {
            mid = (low + high) / 2;

            if (nums[mid] > nums[high]) low = mid + 1;
            else high = mid;
        }


        int k{low};
        int rotated_mid{};

        high = nums.size() - 1;
        low = 0;

        while (low <= high)
        {
            mid = (low + high) / 2;
            rotated_mid = (mid + k) % nums.size();

            if(nums[rotated_mid] == target) return rotated_mid;
            if(nums[rotated_mid] < target) low = mid + 1;
            else high = mid - 1;
        }

        return -1;
    }
};


int main()
{
    vector<int> v{6, 0, 1, 2, 3, 4, 5};
    cout << Solution{}.search(v, 1) << '\n';

    return 0;
}