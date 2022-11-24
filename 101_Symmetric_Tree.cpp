#include <iostream>
#include <vector>
#include <stack>

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
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;

        stack<TreeNode*> traversal{};
        TreeNode* l_current{};
        TreeNode* r_current{};
        
        traversal.push(root->left);
        traversal.push(root->right);

        while (!traversal.empty()) 
        {
            l_current = traversal.top();
            traversal.pop();

            r_current = traversal.top();
            traversal.pop();

            if (l_current && !r_current) return false;
            if (!l_current && r_current) return false;
            
            // Prevent us from putting more nodes in when there's nowhere to traverse
            if (!l_current && !r_current) continue;
            
            if (l_current->val != r_current->val) return false;

            traversal.push(l_current->right);
            traversal.push(r_current->left);

            traversal.push(l_current->left);
            traversal.push(r_current->right);
        }

        return true;
    }
};


int main()
{
    TreeNode llbranch{1};
    TreeNode lrbranch{3};
    TreeNode lbranch{2, nullptr, nullptr};

    TreeNode rlbranch{1};
    TreeNode rrbranch{3};
    TreeNode rbranch{2, nullptr, nullptr};

    TreeNode tree{1, nullptr, &rbranch};

    cout << boolalpha << Solution{}.isSymmetric(&tree) << endl;

    return 0;
}