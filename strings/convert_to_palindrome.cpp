#include <string>
#include <iostream>

bool is_palindrome(std::string A) {
    int left = 0;
    int right = A.length() - 1;
    while (left <= right) {
        if (A[left] != A[right]) {
            return 0;
        }
        left++;
        right--;
    }
    return 1;
}

int convert(std::string A) {
    int left = 0;
    int right = A.length() - 1;
    bool mismatch = 0;
    while (left <= right) {
        std::cout << A[left] << ' ' << A[right] << std::endl;
        if (A[left] != A[right]) {
            mismatch = 1;
            break;
        }
        else {
            left++;
            right--;
        }
    }

    if (!mismatch) {
        return 1;
    }

    std::string first = std::string(A.begin(), A.begin() + left)
                        + std::string(A.begin() + left + 1, A.end());
    std::string second = std::string(A.begin(), A.begin() + right)
                        + std::string(A.begin() + right + 1, A.end());
    std::cout << left << " " << right << "\n";
    std::cout << first << " " << second << "\n";
    return is_palindrome(first) || is_palindrome(second);
}

int main() {
    // std::string A = "abcdcaba";
    // abecbea
    // std::string A = "abaccab";
    std::string A = "epyyevdadveyype";
    std::cout << convert(A);
}