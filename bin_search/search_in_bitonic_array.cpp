#include <iostream>
#include <vector>

int find_turning_point(std::vector<int> &A) {
    int left = 1;
    int right = A.size() - 1;
    int mid = (left + right) / 2;
    while (left < right) {
        if (A[mid] > A[mid - 1] && A[mid] > A[mid + 1]) {
            return mid;
        }
        if (A[mid] > A[mid - 1] && A[mid] < A[mid + 1]) {
            left = mid + 1;
        }
        if (A[mid] < A[mid - 1] && A[mid] > A[mid + 1]) {
            right = mid - 1;
        }
        mid = (left + right) / 2;
    }
    return mid;
}

int increasing_binary_search(std::vector<int> &A, int left_idx,
                             int right_idx, int target) {
    if (A[left_idx] > target || A[right_idx] < target) {
        return -1;
    }

    int left = left_idx;
    int right = right_idx + 1;
    int mid = (left + right) / 2;
    while (left < right) {
        //std::cout << left << ' ' << mid << ' ' << right << ' ' << A[mid] << std::endl;
        if (A[mid] == target) {
            return mid;
        }
        if (A[mid] > target) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
        mid = (left + right) / 2;
    }
    return A[mid] == target? mid: -1;
}

int decreasing_binary_search(std::vector<int> &A, int left_idx,
                             int right_idx, int target) {
    if (A[left_idx] < target || A[right_idx] > target) {
        return -1;
    }

    int left = left_idx;
    int right = right_idx + 1;
    int mid = (left + right) / 2;
    while (left < right) {
        //std::cout << left << ' ' << mid << ' ' << right << std::endl;
        if (A[mid] == target) {
            return mid;
        }
        if (A[mid] > target) {
            left = mid + 1;
        }
        else {
            right = mid;
        }
        mid = (left + right) / 2;
    }
    return A[mid] == target? mid: -1;
}

int bitonic_search(std::vector<int> &A, int B) {
    int turning_idx = find_turning_point(A);
    int increasing_result = increasing_binary_search(A, 0, turning_idx, B);
    int decreasing_result = decreasing_binary_search(A, turning_idx + 1,
                                                     int(A.size() - 1), B);
    if (increasing_result != -1) {
        return increasing_result;
    }
    if (decreasing_result != -1) {
        return decreasing_result;
    }
    return -1;
}

int main() {
    // [1, 2, 3, 4, 5, 6, 1]
    std::vector<int> A = {3, 9, 10, 19, 17, 5, 1};
    // std::vector<int> A = {1, 2, 3, 4, 5, 6, 1};
    // std::vector<int> A = {1, 100, 5, 4, 3, 2, 1};
    int B = 4;
    //std::cout << find_turning_point(A);
    // std::vector<int> A = {0, 1, 2, 3, 4, 5, 6, 7, 8, 10};
    // std::vector<int> A_rot = {10, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    // int left = 0;
    // int right = 9;
    // int B = 9;
    std::cout << bitonic_search(A, B);
    //std::cout << increasing_binary_search(A, 0, 9, 11) << std::endl;
    //std::cout << decreasing_binary_search(A_rot, 0, 9, 100);
}