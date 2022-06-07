#include <iostream>
#include <vector>
#include <stack>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

std::vector<int> preorder_traversal(TreeNode* A) {
    std::vector<int> vals;
    std::stack<TreeNode*> st;

    while (A) {
        st.push(A);
        vals.push_back(A->val);
        A = A->left;
    }

    while (!st.empty()) {
        TreeNode* top = st.top();
        st.pop();
        A = top->right;
        while (A) {
            st.push(A);
            vals.push_back(A->val);
            A = A->left;
        }
    }

    return vals;
}

int main() {
    TreeNode* A = new TreeNode(1);
    A->left = new TreeNode(2);
    A->right = new TreeNode(3);
    A->left->left = new TreeNode(4);
    A->left->right = new TreeNode(5);

    std::vector<int> traversal = preorder_traversal(A);
    for (auto el: traversal) {
        std::cout << el << ' ';
    }
}