#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void update_counter(TreeNode* A, int &counter) {
    if (!A) {
        return;
    }

    if (A->left && std::abs(A->val - A->left->val) == 1) {
        counter++;
    }
    if (A->right && std::abs(A->val - A->right->val) == 1) {
        counter++;
    }
    update_counter(A->left, counter);
    update_counter(A->right, counter);
}

int get_consecutive_nodes(TreeNode* A) {
    int counter = 0;
    update_counter(A, counter);
    return counter;
}

int main() {
    TreeNode* A = new TreeNode(2);
    A->left = new TreeNode(10);
    A->right = new TreeNode(30);
    A->left->left = new TreeNode(20);
    A->left->right = new TreeNode(0);

    std::cout << get_consecutive_nodes(A);
}