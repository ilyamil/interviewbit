#include <iostream>
#include <vector>

int find_max_sum(std::vector<int> &A) {
    int cur_sum = A[0];
    int max_sum = A[0];
    for (int i = 1; i < A.size(); i++) {
        if (cur_sum < 0 && A[i] > A[i - 1]) {
            cur_sum = A[i];
        }
        else {
            cur_sum += A[i];
        }
        max_sum = std::max(max_sum, cur_sum);
    }
    return max_sum;
}

int main() {
    std::vector<int> A = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    //std::vector<int> A = {1, -2, 3, -4, 5, -6};
    //std::vector<int> A = {1, -2, 3};
    std::cout << find_max_sum(A);
}