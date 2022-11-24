#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <map>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.size() == 0) return nullptr;

        int mid{static_cast<int>(nums.size() / 2.0)};

        TreeNode* root_ptr{new TreeNode{nums[mid]}};
        TreeNode* l_current_node{root_ptr};
        TreeNode* r_current_node{root_ptr};

        if (mid != 0)
        {
            l_current_node->left = new TreeNode{nums[0]};
            l_current_node = l_current_node->left;
        }

        if (mid + 1 != nums.size())
        {
            r_current_node->right = new TreeNode{nums[mid + 1]};
            r_current_node = r_current_node->right;
        }

        for (int i = 1, j = mid + 2; i < mid || j < nums.size(); i++, j++)
        {
            if (i < mid)
            {
                l_current_node->right = new TreeNode{nums[i]};
                l_current_node = l_current_node->right;
            }

            if (j < nums.size())
            {
                r_current_node->right = new TreeNode{nums[j]};
                r_current_node = r_current_node->right;
            }
        }

        return root_ptr;
    }
};

int main()
{
    vector<int> nums{0,1,2,3,4,5};

    TreeNode* tree {Solution{}.sortedArrayToBST(nums)};

    return 0;
}