#include <iostream>
#include <vector>
#include <algorithm>

void print_vector(const std::vector<int> &A) {
    for (auto el: A) {
        std::cout << el << ' ';
    }
}

std::vector<int> get_next_permutation(std::vector<int> &A) {
    auto N = A.size();

    // find an index of element greater than preceeding
    int i = N - 1;
    while (i > 0 && A[i - 1] >= A[i]) {
        i--;
    }

    // array is in descending order
    if (i == 0) {
        std::sort(A.begin() + i, A.end());
        return A;
    }
    // find an index of element just larger than the index above
    int j = N - 1;
    while (j > i - 1 && A[i - 1] >= A[j]) {
        j--;
    }
    std::swap(A[i - 1], A[j]);
    std::sort(A.begin() + i, A.end());
    return A;
}

int main() {
    std::vector<int> A = {1, 2, 3};
    //std::vector<int> A = {3, 2, 1};
    //std::vector<int> A = {1, 1, 5};
    //std::vector<int> A = {20, 50, 113};
    print_vector(get_next_permutation(A));
}