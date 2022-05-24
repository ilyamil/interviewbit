#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int get_max_depth(TreeNode* A) {
    if (!A) {
        return 0;
    }
    int left_max = get_max_depth(A->left);
    int right_max = get_max_depth(A->right);
    return std::max(left_max, right_max) + 1;
}

int main() {
    TreeNode* A = new TreeNode(1);
    TreeNode* B = new TreeNode(2);
    TreeNode* C = new TreeNode(3);
    A->left = B;
    B->right = C;

    std::cout << get_max_depth(A);
}