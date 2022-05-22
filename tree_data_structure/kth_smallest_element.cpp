#include <iostream>
#include <stack>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int get_k_smallest(TreeNode* A, int B) {
    std::stack<TreeNode*> st;

    int ans = 0;
    TreeNode* root = A;
    while (true) {
        while (root) {
            st.push(root);
            root = root->left;
        }
        root = st.top();
        st.pop();
        if (--B == 0) {
            ans = root->val;
            break;
        }
        root = root->right;
    }

    return ans;
}

int main() {

}