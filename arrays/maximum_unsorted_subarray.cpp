#include <vector>
#include <iostream>
#include <algorithm>

std::vector<int> find_subarray(std::vector<int> &A) {
    std::vector<int> sorted_ar = A;
    std::sort(sorted_ar.begin(), sorted_ar.end());

    std::vector<int> subarray = {-1, -1};
    for (int i = 0; i < A.size(); i++) {
        if (A[i] != sorted_ar[i]) {
            if (subarray[0] == -1) {
                subarray[0] = i;
            }
            else if (subarray[1] == -1) {
                subarray[1] = i;
            }
            else {
                subarray[1] = std::max(subarray[1], i);
            }
        }
    }

    if (subarray[0] == -1 && subarray[1] == -1) {
        return { -1 };
    }
    return subarray;
}

int main() {
    // std::vector<int> A = {1, 3, 2, 4, 5};
    // std::vector<int> A = {1, 5};
    std::vector<int> A = {1, 1, 10, 10, 15, 10, 15, 10, 10, 15, 10, 15};
    for (auto el: find_subarray(A)) {
        std::cout << el << ' ';
    }
    // [1, 3, 2, 4, 5]
    // [1, 2, 3, 4, 5]
}