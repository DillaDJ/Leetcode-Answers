#include <iostream>
#include <vector>


using namespace std;


class Solution {
public:
    int removeElement(vector<int>& nums, int val) {

        int replace_pos = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            
            if (nums[i] == val) {
                continue;
            }

            nums[replace_pos++] = nums[i];

        }

        return replace_pos;
    }
};


int main() {

    vector<int> test {0, 1, 2, 1, 5};
    
    cout << "k: " << Solution().removeElement(test, 1) << endl;

    for (int i : test) {
        cout << i << endl;
    }


    return 0;
}