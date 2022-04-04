#include <vector>
#include <iostream>
#include <algorithm>

std::vector<int> wave_sort(std::vector<int> &A) {
    int N = A.size();
    if (N <= 1) {
        return A;
    }

    std::sort(A.begin(), A.end());

    std::vector<int> result(N);
    for (int i = 1; i < N; i+=2) {
        result[i - 1] = A[i];
        result[i] = A[i - 1];
    }
    if (N % 2 == 1) {
        result[N - 1] = A[N - 1];
    }
    return result;
}

int main() {
    // std::vector<int> A = {1, 2, 3, 4};
    // std::vector<int> A = {1, 2, 3};
    std::vector<int> A = {2, 1};
    for (auto el: wave_sort(A)) {
        std::cout << el << ' ';
    }
}