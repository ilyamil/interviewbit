#include <vector>
#include <unordered_map>
#include <iostream>

// Time complexity: O(N)
// Space complexity: O(N)
std::vector<int> get_indexes(std::vector<int> &A, int B) {
    std::unordered_map<int, int> element_index;
    for (int i = 0; i < A.size(); i++) {
        if (element_index.find(A[i]) == element_index.end()) {
            if (element_index.find(B - A[i]) == element_index.end()) {
                element_index[B - A[i]] = i;
            }
        }
        else {
            return {element_index[A[i]] + 1, i + 1};
        }
    }
    return {};
}

int main() {
    // std::vector<int> A = {2, 7, 11, 15};
    // int B = 9;
    // std::vector<int> answer = get_indexes(A, B);
    // if (answer.size() == 2) {
    //     std::cout << answer[0] << ' ' << answer[1];
    // }
    // else {
    //     std::cout << "Empty array!";
    // }

    // std::vector<int> A = {2, 2, 7, 11, 15};
    // int B = 4;
    // std::vector<int> answer = get_indexes(A, B);
    // if (answer.size() == 2) {
    //     std::cout << answer[0] << ' ' << answer[1];
    // }
    // else {
    //     std::cout << "Empty array!";
    // }

    // std::vector<int> A = {2, 2, 7, 11, 15};
    // int B = 100;
    // std::vector<int> answer = get_indexes(A, B);
    // if (answer.size() == 2) {
    //     std::cout << answer[0] << ' ' << answer[1];
    // }
    // else {
    //     std::cout << "Empty array!";
    // }

    std::vector<int> A = {4, 7, -4, 2, 2, 2, 3, -5, -3, 9, -4, 9, -7, 7,
                          -1, 9, 9, 4, 1, -4, -2, 3, -3, -5, 4, -7, 7, 9, -4, 4, -8};
    int B = -3;
    std::vector<int> answer = get_indexes(A, B);
    if (answer.size() == 2) {
        std::cout << answer[0] << ' ' << answer[1];
    }
    else {
        std::cout << "Empty array!";
    }
}