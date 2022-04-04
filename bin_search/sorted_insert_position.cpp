#include <iostream>
#include <vector>

int search_insert(std::vector<int> &A, int B) {
    if (A.size() == 1) {
        return B > A[0]? 1: 0;
    }

    int left = 0;
    int right = A.size();
    int mid = (left + right) / 2;
    while (left < right) {
        if (A[mid] > B) {
            right = mid - 1;
        }
        if (A[mid] < B) {
            left = mid + 1;
        }
        if (A[mid] == B) {
            return mid;
        }
        mid = (left + right) / 2;
    }
    // std::cout << left << ' ' << mid << ' ' << right << std::endl;
    return A[left] < B? left + 1: left; 
}

int main() {
    // std::vector<int> A = {1};
    // int B = 2;

    // std::vector<int> A = {1};
    // int B = 0;

    std::vector<int> A = {1, 2, 3};
    int B = 0;

    // std::vector<int> A = {1, 2};
    // int B = 3;

    // std::vector<int> A = {1, 2, 4, 6, 8};
    // int B = 3;

    // std::vector<int> A = {1, 3, 5, 6};
    // int B = 5;

    // std::vector<int> A = {1, 3, 5, 6};
    // int B = 2;

    std::cout << search_insert(A, B);
}