#include <iostream>
#include <vector>

int find_min_steps(std::vector<int> &A, std::vector<int> &B) {
    if (A.size() <= 1) {
        return 0;
    }
    int num_steps = 0;
    for (int i = 1; i < A.size(); i++) {
        num_steps += std::max(std::abs(B[i] - B[i - 1]),
                              std::abs(A[i] - A[i - 1]));
    }
    return num_steps;
}

int main() {
    std::vector<int> A = {0, 1, 1};
    std::vector<int> B = {0, 1, 2};
    std::cout << find_min_steps(A, B);
}