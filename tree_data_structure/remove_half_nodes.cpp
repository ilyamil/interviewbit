#include <vector>
#include <iostream>
#include <stack>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* remove_half_nodes(TreeNode* A) {
    if (!A) {
        return nullptr;
    }

    A->left = remove_half_nodes(A->left);
    A->right = remove_half_nodes(A->right);

    if ((A->left && A->right) || (!A->left && !A->right)) {
        return A;
    }

    TreeNode* child = (A->left) ? A->left: A->right;
    delete A;
    return child;
}

int main() {
    TreeNode* A = new TreeNode(1);
    A->left = new TreeNode(2);;
    A->right = new TreeNode(3);
    A->left->left = new TreeNode(4);

    auto new_A = remove_half_nodes(A);
    std::cout << new_A->val << ' ' << new_A->left->val;
}