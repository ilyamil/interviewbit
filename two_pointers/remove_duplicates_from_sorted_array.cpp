#include <iostream>
#include <vector>

int remove_duplicates(std::vector<int> &A) {
    if (A.size() == 2) {
        return A[1] == A[0]? 1: 2;
    }

    int unique_cnt = 1;
    int duplicate_cnt = 0;
    int slow = 0;
    int fast = 1;
    int prev = A[0];
    while (slow != fast && fast < A.size()) {
        if (A[fast] != prev) {
            slow += 1;
            if (duplicate_cnt > 0) {
                std::swap(A[fast], A[slow]);
                duplicate_cnt = 0;
            }
            unique_cnt++;
            prev = A[slow];
        }
        duplicate_cnt++;
        fast++;
    }
    return unique_cnt;
}

int main() {
    std::vector<int> A = {0, 1, 2, 2, 2, 2, 2, 3};
    auto i = remove_duplicates(A);
    std::cout << i << std::endl;
    for (auto el: A) {
        std::cout << el << ' ';
    }
}