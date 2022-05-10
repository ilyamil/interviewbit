#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

void populate(int i, int cur_sum, int max_sum,
              std::vector<int> &current,
              std::vector<std::vector<int>> &target,
              std::vector<int> &source) {
    if (cur_sum == max_sum) {
        target.push_back(current);
        return;
    }
    if (i >= source.size() || cur_sum > max_sum) {
        return;
    }
    current.push_back(source[i]);
    populate(i, cur_sum + source[i], max_sum, current, target, source);
    current.pop_back();
    populate(i + 1, cur_sum, max_sum, current, target, source);
}

std::vector<std::vector<int>> combination_sum(std::vector<int> &A, int B) {
    std::set<int> candidates_(A.begin(), A.end());
    A = std::vector<int>(candidates_.begin(), candidates_.end());
    std::vector<std::vector<int>> result;
    std::vector<int> current;
    populate(0, 0, B, current, result, A);
    return result;
}

int main() {
    std::vector<int> A = {2, 3, 6, 7};
    int B = 7;
    for (auto combination: combination_sum(A, B)) {
        for (auto el: combination) {
            std::cout << el << ' ';
        }
        std::cout << std::endl;
    }
}