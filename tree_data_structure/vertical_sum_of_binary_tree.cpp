#include <iostream>
#include <vector>
#include <map>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void fill_map(TreeNode* A, int vnum, std::map<int, int> &map) {
    if (!A) {
        return;
    }

    map[vnum] += A->val;

    fill_map(A->left, vnum - 1, map);
    fill_map(A->right, vnum + 1, map);
}

std::vector<int> get_vertical_sum(TreeNode* A) {
    std::map<int, int> vertical_to_sum;
    fill_map(A, 0, vertical_to_sum);
    std::vector<int> sum;
    for (auto [v, s]: vertical_to_sum) {
        sum.push_back(s);
    }
    return sum;
}

int main() {
    TreeNode* A = new TreeNode(1);
    A->left = new TreeNode(2);
    A->right = new TreeNode(3);
    A->left->left = new TreeNode(4);
    A->left->right = new TreeNode(5);
    A->right->left = new TreeNode(6);
    A->right->right = new TreeNode(7);

    auto sums = get_vertical_sum(A);
    for (auto el: sums) {
        std::cout << el << ' ';
    }
}