#include <iostream>
#include <vector>
#include <unordered_map>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void populate_levels(TreeNode* A, std::vector<std::vector<int>>& level_vals,
                     int level) {
    if (!A) {
        return;
    }

    if (level == 0 || level + 1 > level_vals.size()) {
        level_vals.push_back({A->val});
    }
    else {
        level_vals[level].push_back(A->val);
    }

    populate_levels(A->left, level_vals, level + 1);
    populate_levels(A->right, level_vals, level + 1);
}

std::vector<int> reverse_level_order(TreeNode* A) {
    std::vector<std::vector<int>> levels;
    populate_levels(A, levels, 0);

    std::vector<int> reversed_order;
    for (int level_num = levels.size() - 1; level_num >= 0; level_num--) {
        for (auto el: levels[level_num]) {
            reversed_order.push_back(el);
        }
    }

    return reversed_order;
}

int main() {
    TreeNode* A = new TreeNode(3);
    A->left = new TreeNode(9);
    A->right = new TreeNode(20);
    A->right->left = new TreeNode(15);
    A->right->right = new TreeNode(7);

    auto ans = reverse_level_order(A);
    for (auto el: ans) {
        std::cout << el << ' ';
    }
}