#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int has_path_sum(TreeNode* A, int B) {
    if (!A) {
        return 0;
    }
    if (!A->left && !A->right && B - A->val == 0) {
        return 1;
    }

    B -= A->val;
    return has_path_sum(A->left, B) || has_path_sum(A->right, B); 
}

int main() {
    TreeNode* A = new TreeNode(1);
    TreeNode* B = new TreeNode(2);
    TreeNode* C = new TreeNode(3);
    A->left = B;
    B->right = C;

    int S = 2;
    std::cout << has_path_sum(A, S);
}