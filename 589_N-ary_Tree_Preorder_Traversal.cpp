#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;


class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};


class Solution {
public:
    vector<int> preorder_recursive(Node* root) {
        if (root == nullptr) return vector<int> { };
        if (root->children.size() == 0) return vector<int> { root->val };

        vector<int> result { root->val };

        for (int i = 0; i < root->children.size(); i++) {
            vector<int> recursive_result { preorder_recursive(root->children[i]) };            
            for (int n : recursive_result) result.push_back(n);
        }

        return result;        
    }

    
    vector<int> preorder(Node* root) {
        vector<int> result { };
        if (root == nullptr) return result;

        stack<Node*> traversal_stack { };

        traversal_stack.push(root);

        while (!traversal_stack.empty()) {
            Node* current_node { traversal_stack.top() };
            result.push_back(current_node->val);
            traversal_stack.pop();

            for (int i = current_node->children.size() - 1; i >= 0; i--) {
                traversal_stack.push(current_node->children[i]);
            }
        }

        return result;
    }
};


Node* convert_vector_to_tree(vector<int> vec) {

    if (vec.size() == 0) return nullptr;


    Node* root;
    Node* prevNode;

    queue<Node*> parents;
    

    for (int i = 0; i < vec.size(); i++)
    {
        if (!vec[i]) {
            if (parents.size() > 1) parents.pop();            
            continue;
        }
        
        Node* current_node { new Node(vec[i], vector<Node*> {}) }; 

        if (parents.empty()) {
            root = current_node;
        }
        else {
            parents.front()->children.push_back(current_node);
        }

        parents.push(current_node);
    }
    
    return root;
}


int main() {

    Node* tree = convert_vector_to_tree(vector<int> {1, NULL, 3, 2, 4, NULL, 5, 6});

    vector<int> traversed = Solution().preorder(tree);

    for (int i : traversed) cout << i << endl;

    return 0;
}