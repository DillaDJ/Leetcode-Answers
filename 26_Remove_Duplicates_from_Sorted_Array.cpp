#include <iostream>
#include <vector>


using namespace std;


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int last_pos = 1;
        
        for (int i = 0; i < nums.size() - 1; i++) {
            
            if (nums[i] == nums[i + 1]) continue;
            nums[last_pos++] = nums[i + 1];
            
        }

        return last_pos;
    }
};


int main() {

    vector<int> input { 0,0,1,1,1,2,2,3,3,4 };

    cout << Solution().removeDuplicates(input) << endl;

    for (int i : input)
    {  
        cout << i << ", ";
    }
    

    return 0;
}