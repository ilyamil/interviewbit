#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

void populate(std::set<std::vector<int>> &target,
              std::vector<int> &current,
              std::vector<int> &source,
              int start, int max_len) {
    if (current.size() == max_len) {
        target.insert(current);
        return;
    }
    for (int i = start; i < source.size(); i++) {
        current.push_back(source[i]);
        populate(target, current, source, i + 1, max_len);
        current.pop_back();
    }
}

std::vector<std::vector<int>> subsets(std::vector<int> &A) {
    std::sort(A.begin(), A.end());
    std::set<std::vector<int>> subsets_;
    for (int i = 0; i <= A.size(); i++) {
        std::vector<int> subset_;
        populate(subsets_, subset_, A, 0, i);
    }
    return {subsets_.begin(), subsets_.end()};
}   

void print_vecvec(std::vector<std::vector<int>> &A) {
    for (auto subset: A) {
        for (auto el: subset) {
            std::cout << el << ' ';
        }
        std::cout << std::endl;
    }    
}

int main() {
    // std::vector<int> A = {1, 2, 3};
    // auto subsets_ = subsets(A);
    // print_vecvec(subsets_);

    std::vector<int> A = {1};
    auto subsets_ = subsets(A);
    print_vecvec(subsets_);
}