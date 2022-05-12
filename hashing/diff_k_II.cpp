#include <vector>
#include <iostream>
#include <unordered_set>

int check_diff(const std::vector<int> &A, int B) {
    std::unordered_set<int> index;
    for (int i = 0; i < A.size(); i++) {
        if (index.count(A[i] - B) || index.count(A[i] + B)) {
            return 1;
        }
        else {
            index.insert(A[i]);
        }
    }
    return 0;
}

int main() {
    std::vector<int> A = {77, 28, 19, 21, 67, 15, 53, 25, 82, 52, 8, 94,
                          50, 30, 37, 39, 9, 43, 35, 48, 82, 53, 16, 20,
                          13, 95, 18, 67, 77, 12, 93, 0};
    int B = 53;
    std::cout << check_diff(A, B);

    // std::vector<int> A = {1, 5, 3};
    // int B = 2;
    // std::cout << check_diff(A, B);

    // std::vector<int> A = {11, 85, 100, 44, 3, 32, 96, 72, 93, 76, 67, 93, 63, 5, 10, 45, 99, 35, 13};
    // int B = 60;
    // std::cout << check_diff(A, B);
}