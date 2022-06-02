#include <vector>
#include <iostream>


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void pathfinder(TreeNode* A, int target,
                std::vector<int>& current_path,
                std::vector<int>& path) {
    current_path.push_back(A->val);
    if (A->val == target) {
        path = current_path;
        return;
    }

    if (A->left) {
        pathfinder(A->left, target, current_path, path);
    }
    if (A->right) {
        pathfinder(A->right, target, current_path, path);
    }
    current_path.pop_back();
}

std::vector<int> find_path(TreeNode* A, int B) {
    std::vector<int> current_path;
    std::vector<int> path;
    pathfinder(A, B, current_path, path);
    return path;
}


int main() {
    TreeNode* A = new TreeNode(1);
    A->left = new TreeNode(2);;
    A->right = new TreeNode(3);
    A->right->right = new TreeNode(4);

    std::vector<int> path = find_path(A, 4);
    for (auto el: path) {
        std::cout << el << ' ';
    }
}