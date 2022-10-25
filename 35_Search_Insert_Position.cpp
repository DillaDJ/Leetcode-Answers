#include <iostream>
#include <vector>


using namespace std;


class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {

        if (nums.size() == 1) {
            if (target > nums[0]) {
                return 1;
            }
            else {
                return 0;
            }
        }

        vector<int> a { vector<int>(nums.begin(), nums.end() - (nums.size() / 2)) };
        vector<int> b { vector<int>(nums.end() - (nums.size() / 2), nums.end()) };

        if (target == a[0] or (a.size() == 1 and target < a[0])) {
            return 0;
        }
        else if (target == b[0] or (b.size() == 1 and a.size() == 1 and target < b[0])) {
            return nums.size() / 2  + nums.size() % 2;
        }
        else if (b.size() == 1 and target > b[0]) {
            return nums.size() / 2 + nums.size() % 2 + 1;
        }

        if(target > b[0]) {
            return nums.size() / 2 + nums.size() % 2 + searchInsert(b, target);
        }
        else {
            return searchInsert(a, target);
        }

    }
};


int main() {

    vector<int> test { 1, 3, 5 };
    
    cout << Solution().searchInsert(test, 6) << endl;

    return 0;
}