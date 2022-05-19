#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>

std::vector<int> get_intersection(std::vector<int> &A,
                                  std::vector<int> &B,
                                  std::vector<int> &C) {
    std::unordered_map<int, std::set<int>> counter;

    for (auto el: A) {
        counter[el].insert(1);
    }

    for (auto el: B) {
        counter[el].insert(2);
    }

    for (auto el: C) {
        counter[el].insert(3);
    }

    std::set<int> answer;
    for (auto &kv: counter) {
        if (kv.second.size() >= 2) {
            answer.insert(kv.first);
        }
    }
    return {answer.begin(), answer.end()};
}

int main() {
    std::vector<int> A = {1, 1, 2};
    std::vector<int> B = {2, 3};
    std::vector<int> C = {3};
    
    for (auto el: get_intersection(A, B, C)) {
        std::cout << el << ' ';
    }
}