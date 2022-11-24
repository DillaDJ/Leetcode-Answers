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
    int maxDepth(TreeNode* root) 
    {
        if(!root) return 0;
        int l_depth = maxDepth(root->left);
        int r_depth = maxDepth(root->right);
        return max(l_depth, r_depth) + 1;
    }
};


int main()
{
    TreeNode llbranch{1};
    TreeNode lrbranch{3};
    TreeNode lbranch{2, &llbranch, &lrbranch};

    TreeNode rlbranch{1};
    TreeNode rrbranch{3};
    TreeNode rbranch{2, &rlbranch, &rrbranch};

    TreeNode tree{1, nullptr, &rbranch};

    cout << Solution{}.maxDepth(&tree) << endl;

    return 0;
}