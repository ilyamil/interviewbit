#include <iostream>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int solve(TreeNode* root, int sum) {
    sum = (sum * 10 + root->val) % 1003;
    if (!root->left && !root->right) {
        return sum;
    }

    int left = 0;
    int right = 0;
    if (root->left) {
        left = solve(root->left, sum);
    }
    if (root->right) {
        right = solve(root->right, sum);
    }
    return left + right;
}

int sum_numbers(TreeNode* A) {
    return solve(A, 0) % 1003;
}

int main() {
    TreeNode* A = new TreeNode(1);
    A->left = new TreeNode(2);;
    A->right = new TreeNode(3);

    std::cout << sum_numbers(A);
}