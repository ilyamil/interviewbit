#include <iostream>
#include <vector>

int less_or_equal_cnt(std::vector<int> &A, int B) {
    int left = 0;
    int right = A.size();
    int idx = left + (right - left) / 2;
    while (left < right) {
        if (A[idx] <= B) {
            left = idx + 1;
        }
        else {
            right = idx;
        }
        idx = left + (right - left) / 2;
    }
    return idx;
}

int main() {
    std::vector<int> A = {1, 2, 2, 2, 2, 5, 6, 7, 8};
    std::cout << less_or_equal_cnt(A, 8);
}