#include <iostream>
#include <vector>
#include <stack>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* build(std::vector<int> &preorder, std::vector<int> &inorder,
                int &root_idx, int left, int right) {
    if (left > right) {
        return nullptr;
    }
    int pivot = left;
    while (inorder[pivot] != preorder[root_idx]) {
        pivot++;
    }
    root_idx++;
    TreeNode* node = new TreeNode(inorder[pivot]);
    node->left = build(preorder, inorder, root_idx, left, pivot - 1);
    node->right = build(preorder, inorder, root_idx, pivot + 1, right);
    return node;
}

TreeNode* build_tree(std::vector<int> &A, std::vector<int> &B) {
    int root_idx = 0;
    return build(A, B, root_idx, 0, A.size() - 1);
}

int main() {

}