#include <iostream>
#include <vector>
#include <stack>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

std::vector<int> postorder_traversal(TreeNode* A) {
    std::vector<int> vals;
    std::stack<TreeNode*> st;
    st.push(A);

    while (!st.empty()) {
        TreeNode* cur = st.top();
        st.pop();

        vals.push_back(cur->val);

        if (cur->left) {
            st.push(cur->left);
        }
        if (cur->right) {
            st.push(cur->right);
        }
    }

    return {vals.rbegin(), vals.rend()};
}

int main() {
    TreeNode* A = new TreeNode(1);
    A->left = new TreeNode(2);
    A->right = new TreeNode(3);
    A->left->left = new TreeNode(4);
    A->left->right = new TreeNode(5);

    std::vector<int> traversal = postorder_traversal(A);
    for (auto el: traversal) {
        std::cout << el << ' ';
    }
}