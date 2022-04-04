#include <iostream>
#include <vector>

int find_max_difference(std::vector<int> &A) {
    int min_vp = A[0];
    int max_vp = A[0];
    int min_vm = A[0];
    int max_vm = A[0];
    for (auto i = 1; i < A.size(); i++) {
        int cur_vp = A[i] + i;
        min_vp = std::min(cur_vp, min_vp);
        max_vp = std::max(cur_vp, max_vp);

        int cur_vm = A[i] - i;
        min_vm = std::min(cur_vm, min_vm);
        max_vm = std::max(cur_vm, max_vm);
    }
    return std::max(max_vp - min_vp, max_vm - min_vm);
}

int main() {
    std::vector<int> A = {1, 3, -1};
    std::cout << find_max_difference(A);
}