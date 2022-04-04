#include <vector>
#include <iostream>

void merge(std::vector<int> &A, std::vector<int> &B) {
    std::vector<int> tmp(A.begin(), A.end());

    int N = A.size();
    int M = B.size();
    A.resize(N + M, 0);

    int a_ptr = 0;
    int b_ptr = 0;
    int tmp_ptr = 0;
    while (b_ptr < M && tmp_ptr < N) {
        if (tmp[tmp_ptr] > B[b_ptr]) {
            A[a_ptr++] = B[b_ptr++];
        }
        else {
            A[a_ptr++] = tmp[tmp_ptr++];
        }
    }

    while (b_ptr < M) {
        A[a_ptr++] = B[b_ptr++];
    }
    while (tmp_ptr < N) {
        A[a_ptr++] = tmp[tmp_ptr++];
    }

    for (auto el: A) {
        std::cout << el << ' ';
    }
}

int main() {
    std::vector<int> A = {1, 5, 8, 9};
    std::vector<int> B = {6, 9};
    merge(A, B);
    // 1, 5, 8, 9, 0, 0
    // 1, 5, 6, 9, 8, 0
    // 1, 5, 6, 
}