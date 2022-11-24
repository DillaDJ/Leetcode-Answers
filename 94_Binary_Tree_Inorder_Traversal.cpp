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
    vector<int> inorderTraversal(TreeNode* root) 
    {
        vector<int> order{};
        if (root == nullptr) return order;

        stack<TreeNode*> traversal{};
        TreeNode* current{root};

        while (current != nullptr || !traversal.empty()) {
            while (current != nullptr) {
                traversal.push(current);
                current = current->left;
            }
            current = traversal.top();
            traversal.pop();

            order.push_back(current->val);
            current = current->right;
        }

        return order;
    }
};


int main()
{
    TreeNode llbranch{1};
    TreeNode lrbranch{2};
    TreeNode lbranch{2, &llbranch, nullptr};

    TreeNode rlbranch{5};
    TreeNode rrbranch{5};
    TreeNode rbranch{4, nullptr, nullptr};

    TreeNode tree{3, &lbranch, nullptr};

    vector<int> nodes{Solution{}.inorderTraversal(&tree)};

    return 0;
}