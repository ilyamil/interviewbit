#include <iostream>
#include <vector>


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


TreeNode* build_BST(const std::vector<int> &A) {
    if (A.size() == 0) {
        return nullptr;
    }
    if (A.size() == 1) {
        return new TreeNode(A[0]);
    }

    int mid = A.size() / 2;
    TreeNode* root = new TreeNode(A[mid]);

    std::vector<int> left(A.begin(), A.begin() + mid);
    std::vector<int> right(A.begin() + mid + 1, A.end());
    root->left = build_BST(left);
    root->right = build_BST(right);

    return root;
}

int main() {

}