#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        
        for (int i = 1; i < nums.size(); i++) {
            nums[i] += nums[i - 1];
        }

        return nums;
    }
};


int main() {

    vector<int> list { 1, 2, 3, 4 };

    vector<int> test = Solution().runningSum(list);

    for (int i : test) {
        cout << i << endl;
    }

    return 0;
}