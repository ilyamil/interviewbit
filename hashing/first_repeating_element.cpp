#include <iostream>
#include <vector>
#include <unordered_map>

int get_first_repeating_element(std::vector<int> &A) {
    std::unordered_map<int, int> unique;
    int min_idx = A.size();
    for (int i = A.size() - 1; i >= 0; i--) {
        if (unique.find(A[i]) != unique.end()) {
            unique[A[i]] = i;
            min_idx = std::min(i, min_idx);
        }
        else {
            unique[A[i]] = -1;
        }
    }
    if (min_idx == A.size()) {
        return -1;
    }
    return A[min_idx];
}

int main() {
    // std::vector<int> A = {10, 5, 3, 4, 3, 5, 6};
    // std::cout << get_first_repeating_element(A);

    // std::vector<int> A = {1, 2, 3, 4, 5};
    // std::cout << get_first_repeating_element(A);

    // std::vector<int> A = {1, 2, 3, 4, 5, 5};
    // std::cout << get_first_repeating_element(A);

    std::vector<int> A = {1, 1, 2, 3, 4, 5, 5};
    std::cout << get_first_repeating_element(A);
}