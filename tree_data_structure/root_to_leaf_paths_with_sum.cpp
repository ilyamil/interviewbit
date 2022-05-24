#include <iostream>
#include <vector>
#include <stack>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void populate(TreeNode* A, std::vector<int> current, int B,
              std::vector<std::vector<int>> &ans) {
    if (!A) {
        return;
    }

    current.push_back(A->val);
    B -= A->val;
    if (!A->left && !A->right && B == 0) {
        ans.push_back(current);
        return;
    }

    populate(A->left, current, B, ans);
    populate(A->right, current, B, ans);
}

std::vector<std::vector<int>> pathSum(TreeNode* A, int B) {
    std::vector<std::vector<int>> ans;
    std::vector<int> path;
    populate(A, path, B, ans);
    return ans;
}

int main() {

}