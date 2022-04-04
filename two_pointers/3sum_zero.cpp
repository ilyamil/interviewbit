#include <vector>
#include <algorithm>
#include <iostream>
#include <set>

std::vector<std::vector<int>> three_sum_zero(std::vector<int> &A) {
    std::sort(A.begin(), A.end());

    int N = A.size() - 1;
    std::set<std::vector<int>> triplets;
    for (int i = 0; i <= N; i++) {
        int left = i + 1;
        int right = N;
        while (left < right) {
            if (A[i] == -(A[left] + A[right])) {
                triplets.insert({A[i], A[left], A[right]});
                left++;
                right--;
            }
            else if (A[i] > -(A[left] + A[right])) {
                right--;
            }
            else {
                left++;
            }
        }
    }
    return {triplets.begin(), triplets.end()};
}

int main() {
    // std::vector<int> A = {-1, 0, 1, 2, -1, -4};
    std::vector<int> A = {1, -4, 0, 0, 5, -5, 1, 0, -2,
                          4, -4, 1, -1, -4, 3, 4, -1, -1, -3};
    for (auto triplet: three_sum_zero(A)) {
        std::cout << triplet[0] << ' ' << triplet[1] << ' ' << triplet[2] << std::endl;
    }
}