#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

std::string find_prefix(std::vector<std::string> &A) {
    if (A.size() == 0) {
        return "";
    }
    if (A.size() == 1) {
        return A[0];
    }

    std::sort(A.begin(), A.end());
    if (A[0][0] != A[1][0]) {
        return "";
    }

    int end = 0;
    for (auto i = 0; i < A[0].length(); i++) {
        for (auto j = 1; j < A.size(); j++) {
            if (A[j][i] != A[0][i]) {
                return std::string(A[0].begin(), A[0].begin() + end);
            }
        }
        end++;
    }
    return A[0];
}

int main() {
    std::vector<std::string> A = {"abcdefgh", "aefghijk", "abcefgh"};
    // std::vector<std::string> A = {"abc", "abc", "abc"};
    // std::vector<std::string> A = {"a", "b", "c"};
    // std::vector<std::string> A = {"a"};
    // std::vector<std::string> A = {"abcd", "abcd", "efgh"};
    std::cout << find_prefix(A);
}