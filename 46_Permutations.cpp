#include <iostream>
#include <unordered_map>
#include <vector>


using namespace std;


class Solution 
{
public:
    void DFS(vector<int>& nums, vector<vector<int>>& out, int begin = 0)
    {
        if (begin >= nums.size())
        {
            out.push_back(nums);
            return;
        }

        for (int i{begin}; i < nums.size(); ++i)
        {
            swap(nums[begin], nums[i]);

            DFS(nums, out, begin + 1);

            swap(nums[begin], nums[i]);
        }
    }


    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<vector<int>> result{};

        DFS(nums, result);

        return result;
    }
};


int main()
{
    vector<int> in{1, 2, 3};
    vector<vector<int>> out{Solution{}.permute(in)};

    for (vector<int> v : out)
    {
        for (int i : v)
            cout << i << ' ';
        cout << endl;
    }

    return 0;
}