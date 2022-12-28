#include <iostream>
#include <vector>
#include <map>

using namespace std;


class Solution {
public:
    int maxArea(vector<int>& height)
    {
        // Sliding window
        int num_elements{static_cast<int>(height.size())};
        int r{num_elements - 1};
        int l{};

        int area{};

        while(r != l)
        {
            int potential_max{min(height[l], height[r]) * (r - l)};
            if (potential_max > area) area = potential_max;

            if(height[l] >= height[r]) --r;
            else ++l;
        }
        
        return area;
    }
};



int main() 
{
    vector<int> height = {10,9,8,7,6,5,4,3,2,1};
    
    cout << Solution{}.maxArea(height) << endl;

    return 0;

}