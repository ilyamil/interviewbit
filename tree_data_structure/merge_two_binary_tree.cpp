#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* merge_(TreeNode* A, TreeNode* B) {
    if (!A && !B) {
        return nullptr;
    }
    else if (!A && B) {
        return B;
    }
    else if (A && !B) {
        return A;
    }
    else {
        A->val += B->val;
        A->left = merge_(A->left, B->left);
        A->right = merge_(A->right, B->right);
        return A;
    }
}

// TreeNode* merge(TreeNode* A, TreeNode* B) {
//     TreeNode* merged_tree = A;

// }

int main() {
    TreeNode* A = new TreeNode(1);
    A->left = new TreeNode(2);

    TreeNode* B = new TreeNode(4);
    B->left = new TreeNode(3);
    B->right = new TreeNode(3);

    TreeNode* N = merge_(A, B);
    std::cout << N->val << ' ' << N->left->val << ' ' << N->right->val;
}