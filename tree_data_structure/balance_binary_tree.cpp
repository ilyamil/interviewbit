#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int is_balanced_(TreeNode* A) {
    if (!A) {
        return 0;
    }
    int left = is_balanced_(A->left);
    int right = is_balanced_(A->right);
    if (left == -1 || right == -1 || std::abs(left - right) > 1) {
        return -1;
    }
    return 1 + std::max(left, right);
}

int is_balanced(TreeNode* A) {
    return is_balanced_(A) != -1? 1: 0;
}

int main() {
    TreeNode* A = new TreeNode(1);
    A->left = new TreeNode(2);
    A->right = new TreeNode(3);

    std::cout << is_balanced(A);
}