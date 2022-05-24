#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int get_min_depth(TreeNode* A) {
    if (!A) {
        return 0;
    }
    if (!A->left) {
        return 1 + get_min_depth(A->right);
    }
    if (!A->right) {
        return 1 + get_min_depth(A->left);
    }
    return std::min(get_min_depth(A->left), get_min_depth(A->right)) + 1;
}

int main() {
    TreeNode* A = new TreeNode(1);
    TreeNode* B = new TreeNode(2);
    TreeNode* C = new TreeNode(3);
    TreeNode* D = new TreeNode(5);
    A->left = B;
    A->right = D;
    B->right = C;

    std::cout << get_min_depth(A);
}