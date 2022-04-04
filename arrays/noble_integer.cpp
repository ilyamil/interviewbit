#include <vector>
#include <iostream>
#include <algorithm>

int check_noble_integer(std::vector<int> &A) {
    int N = A.size();
    if (N == 0) {
        return -1;
    }

    std::sort(A.begin(), A.end());
    for (int i = 0; i < N - 1; i++) {
        if (A[i] < A[i + 1] && A[i] == N - i - 1) {
            return 1;
        }
    }
    if (A[N - 1] == 0) {
        return 1;
    }
    return -1;
}

int main() {
    // std::vector<int> vec = {3, 2, 1, 3};
    std::vector<int> vec = {0, 0, 0};
    // std::vector<int> vec = {0, 3, 5};
    // std::vector<int> vec = {5, 6, 7};
    //std::vector<int> vec = {1, 2, 7, 0, 9, 3, 6, 0, 6};
    std::cout << check_noble_integer(vec);
}
