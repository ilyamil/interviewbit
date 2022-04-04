#include <iostream>
#include <vector>
#include <algorithm>

int lower_bound(std::vector<int> &A, int B) {
    int left = 0;
    int right = A.size();
    int mid = (left + right) / 2;
    while (left < right) {
        // std::cout << left << ' ' << mid << ' ' << right << std::endl;
        if (A[mid] < B) {
            left = mid + 1;
        }
        else {
            right = mid;
        }
        mid = (left + right) / 2;
    }
    return left;
}

std::vector<int> search(std::vector<int> &A, int B) {
    if (A.size() == 1) {
        return A[0] == B? std::vector<int>{0, 0}: std::vector<int>{-1, -1};
    }

    int lb = lower_bound(A, B);
    int ub = lower_bound(A, B + 1) - 1;
    if (A[lb] != B || A[ub] != B) {
        return {-1, -1};
    }
    return {lb, ub};
}

int main() {
    // std::vector<int> A = {1, 1, 2, 2, 2, 4, 4};
    // int B = 1;

    // std::cout << lower_bound(A, 3);
    // std::vector<int> A = {5, 7, 7, 8, 8, 10};
    // int B = 8;
    // std::cout << lower_bound(A, B);
    //std::cout << std::lower_bound(A.begin(), A.end(), B) - A.begin();

    // std::vector<int> A = {5, 7, 7, 7, 8, 8, 10};
    // int B = 7;

    // std::vector<int> A = {5};
    // int B = 5;

    // std::vector<int> A = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    // 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
    // 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
    // 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
    // 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
    // 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
    // 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
    // 8, 8, 8, 8, 8, 8, 8, 8,
    // 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9,
    // 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10};
    // int B = 10;

    std::vector<int> A = {5, 7, 7, 7, 8, 8, 10, 10};
    int B = 10;
    // std::cout << lower_bound(A, B + 1);
    auto res = search(A, B);
    std::cout << res[0] << ' ' << res[1];
}