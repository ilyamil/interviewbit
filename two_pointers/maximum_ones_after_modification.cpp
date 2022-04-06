#include <iostream>
#include <vector>

int cnt_max_ones(std::vector<int> &A, int B) {
    int num_zeros = 0;
    int max_len = 0;
    int left = 0;
    for (int i = 0; i < A.size(); i++) {
        if (A[i] == 0) {
            num_zeros++;
        }
        if (num_zeros > B) {
            if (A[left] == 0) {
                num_zeros--;
            }
            left++;
        }
        if (num_zeros <= B) {
            max_len = std::max(max_len, i - left + 1);
        }
    }
    return max_len;
}

int main() {
    // std::vector<int> A = {1, 0, 0, 1, 0, 1, 0, 1, 0, 1};
    // int B = 2;
    std::vector<int> A = {1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1};
    int B = 2;
    std::cout << cnt_max_ones(A, B) << ' ';
}