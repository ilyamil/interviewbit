#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


int isSameTree(TreeNode* A, TreeNode* B) {
    if ((!A && B) || (A && !B) || (A && B && (A->val != B->val))) {
        return 0;
    }
    if (!A && !B) {
        return 1;
    }

    int left_res = isSameTree(A->left, B->left);;
    int right_res = isSameTree(A->right, B->right);;

    return left_res * right_res;
}

int main() {
    TreeNode* A = new TreeNode(1);
    A->left = new TreeNode(2);
    A->right = new TreeNode(3);

    TreeNode* B = new TreeNode(1);
    B->left = new TreeNode(2);
    B->right = new TreeNode(3);
    B->right->right = new TreeNode(4);

    std::cout << isSameTree(nullptr, nullptr);
}