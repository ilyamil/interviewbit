#include <iostream>
#include <vector>
#include <stack>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

std::vector<int> inorder_traversal(TreeNode* A) {
    std::vector<int> ans;
    std::stack<TreeNode*> st;

    TreeNode* cur = A;
    while (!st.empty() || cur) {
        while (cur) {
            st.push(cur);
            cur = cur->left;
        }
        TreeNode* top = st.top();
        st.pop();
        ans.push_back(top->val);
        cur = top->right;
    }

    return ans;
}

int main() {
    TreeNode* A = new TreeNode(1);
    A->left = new TreeNode(2);
    A->right = new TreeNode(3);
    A->left->left = new TreeNode(4);
    A->left->right = new TreeNode(5);

    std::vector<int> traversal = inorder_traversal(A);
    for (auto el: traversal) {
        std::cout << el << ' ';
    }
}