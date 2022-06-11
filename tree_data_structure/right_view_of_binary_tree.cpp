#include <iostream>
#include <vector>

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

std::vector<int> get_right_view(TreeNode* A) {
    std::vector<std::vector<int>> levels;
    populate_levels(A, levels, 0);
    std::vector<int> right_view;
    for (auto &level_nodes: levels) {
        int max_idx = level_nodes.size() - 1;
        right_view.push_back(level_nodes[max_idx]);
    }
    return right_view;
}

int main() {
    TreeNode* A = new TreeNode(1);
    A->left = new TreeNode(2);
    A->right = new TreeNode(3);
    A->left->left = new TreeNode(4);

    auto ans = get_right_view(A);
    for (auto el: ans) {
        std::cout << el << ' ';
    }
}