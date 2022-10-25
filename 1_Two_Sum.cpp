#include <iostream>
#include <vector>
#include <map>

using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<int> result = {-1, -1};
        map<int, vector<int>> indexMap;
        
        for (int i = 0; i < nums.size(); i++) {
            
            if (indexMap.count(nums[i]) > 0) {
                indexMap[nums[i]].push_back(i);

            } else {
                vector<int> intVector = { i };
                indexMap[nums[i]] = intVector;
            }
        }
        
        for (int i = 0; i < nums.size(); i++) {
            int difference = target - nums[i];

            if (indexMap.count(difference) > 0) {
                if (i == indexMap[difference][0]) {
                    if (indexMap[difference].size() > 1) {
                        vector<int> resultVector = { i, indexMap[difference][1] }; 
                        result = resultVector;
                        break;
                    }
                    
                    continue;
                }

                vector<int> resultVector = { i, indexMap[difference][0] }; 
                result = resultVector;
                break;
            }
        }

        return result;
    }
};



int main() {

    vector<int> nums = {3,1,3};
    int target = 6;

    vector<int> result = Solution().twoSum(nums, target);

    cout << result[0] << ", " << result[1];

    return 0;

}