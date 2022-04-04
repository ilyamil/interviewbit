#include <iostream>
#include <vector>

int find_maxmin_sum(std::vector<int> &A) {
    int max = INT32_MIN;
    int min = INT32_MAX;
    for (int i = 0; i < A.size(); i++) {
        if (A[i] > max) {
            max = A[i];
        }
        else if (A[i] < min) {
            min = A[i];
        }
    }
    return max + min;
}

int main() {
    std::vector<int> A = {-2, 1, -4, 5, 3};
    std::cout << find_maxmin_sum(A);
}