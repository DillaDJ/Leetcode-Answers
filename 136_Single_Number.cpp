#include <vector>

using namespace std;


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result{};

        for (int i = 0; i < nums.size(); i++)
            result ^= nums[i];
        
        return result;
    }
};

int main()
{
    vector<int> v{1, 6, 1, 3, 4, 3, 6 };

    Solution{}.singleNumber(v);

    return 0;
}