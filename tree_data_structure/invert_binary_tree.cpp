#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* invert_tree(TreeNode* A) {
    if (!A) {
        return nullptr;
    }

    TreeNode* tmp = A->right;
    A->right = A->left;
    A->left = tmp;

    A->left = invert_tree(A->left);
    A->right = invert_tree(A->right);

    return A;
}

int main() {
    TreeNode* A = new TreeNode(1);
    A->left = new TreeNode(2);
    A->left->left = new TreeNode(4);
    A->left->right = new TreeNode(5);
    A->right = new TreeNode(3);
    A->right->left = new TreeNode(6);
    A->right->right = new TreeNode(7);

    TreeNode* inverted = invert_tree(A);
    std::cout << inverted->left->val << ' ' << inverted->right->val << '\n';
    std::cout << inverted->left->left->val << ' ' << inverted->left->right->val;
}