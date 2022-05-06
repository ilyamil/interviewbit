#include <iostream>
#include <vector>

void permute(std::vector<int> &nums, int start,
            std::vector<std::vector<int>> &ans) {
    if (start >= nums.size()) {
        ans.push_back(nums);
        return;
    }

    for (int i = start; i < nums.size(); i++) {
        std::swap(nums[i], nums[start]);
        permute(nums, start + 1, ans);
        std::swap(nums[i], nums[start]);
    }
}

std::vector<std::vector<int>> get_all_permutations(std::vector<int> &A) {
    std::vector<std::vector<int>> answer;
    permute(A, 0, answer);
    return answer;
}

int main() {
    std::vector<int> A = {1};
    auto permutations = get_all_permutations(A);
    for (auto perm: permutations) {
        for (auto el: perm) {
            std::cout << el << ' ';
        }
        std::cout << '\n';
    }
}