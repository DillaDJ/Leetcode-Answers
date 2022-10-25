#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        
        int left_sum = 0;
        int sum = 0;

        for (int i : nums) {
            sum += i;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (left_sum == sum - left_sum - nums[i]) {
                return i;
            }

            left_sum += nums[i];
        }

        return -1;
    }
};


int main() {

    vector<int> test {1,7,3,6,5,6};

    cout << Solution().pivotIndex(test) << endl;

    return 0;
}