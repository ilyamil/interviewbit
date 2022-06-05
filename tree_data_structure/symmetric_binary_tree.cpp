#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int is_symmetric(TreeNode* A, TreeNode* B) {
    if ((!A && B) || (A && !B) || (A && B && (A->val != B->val))) {
        return 0;
    }
    if (!A && !B) {
        return 1;
    }

    int first_pair = is_symmetric(A->right, B->left);
    int second_pair = is_symmetric(A->left, B->right);
    return first_pair * second_pair;
}

int isSymmetric(TreeNode* A) {
    if (!A || (!A->left && !A->right)) {
        return 1;
    }
    return is_symmetric(A->left, A->right);
}

int main() {
    TreeNode* A = new TreeNode(1);
    A->left = new TreeNode(2);
    A->right = new TreeNode(2);
    A->right->right = new TreeNode(3);
    A->left->left = new TreeNode(3);

    std::cout << isSymmetric(A);
}