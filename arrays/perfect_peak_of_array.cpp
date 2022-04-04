#include <vector>
#include <iostream>

int find_perfect_peak(std::vector<int> &A) {
    int N = A.size();

    std::vector<int> max_vec(N, A[0]);
    for (int i = 1; i < N; i++) {
        max_vec[i] = std::max(max_vec[i - 1], A[i - 1]);
    }

    std::vector<int> min_vec(N, A[N - 1]);
    for (int i = N - 2; i >= 0; i--) {
        min_vec[i] = std::min(min_vec[i + 1], A[i + 1]);
    } 

    for (int i = 1; i < N - 1; i++) {
        if (A[i] > max_vec[i] && A[i] < min_vec[i]) {
            return 1;
        }
    }
    return 0;
}

int main() {
    //std::vector<int> A = {5, 1, 4, 3, 6, 8, 10, 7, 9};
    //std::vector<int> A = {1, 3, 1};
    std::vector<int> A = {5, 1, 4, 4};
    // for (auto el: A) {
    //     std::cout << el << ' ';
    // }
    // std::cout << std::endl;
    auto i = find_perfect_peak(A);
    std::cout << i;
}