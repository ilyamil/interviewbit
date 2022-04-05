#include <iostream>
#include <vector>

int remove(std::vector<int> &A, int B) {
    int cnt = 0;
    for (int i = 0; i < A.size(); i++) {
        if (A[i] != B) {
            A[cnt++] = A[i];
        }
    }
    return cnt;
}

int main() {
    // std::vector<int> A = {4, 1, 1, 2, 1, 3};
    // int B = 1;
    std::vector<int> A = {1, 4, 1, 1, 2, 1, 3};
    int B = 1;
    // std::vector<int> A = {4, 2, 3};
    // int B = 1;
    auto i = remove(A, B);
}