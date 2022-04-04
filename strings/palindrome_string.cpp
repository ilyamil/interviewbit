#include <string>
#include <iostream>

bool is_palindrome(std::string A) {
    int left = 0;
    int right = A.length() - 1;
    while (left <= right) {
        int left_char = std::tolower(A[left]);
        int right_char = std::tolower(A[right]);
        if (!((left_char >= 'a' && left_char <= 'z')
            || (left_char >= '0' && left_char <= '9'))) {
            left++;
            continue;
        }
        if (!((right_char >= 'a' && right_char <= 'z')
            || (right_char >= '0' && right_char <= '9'))) {
            right--;
            continue;
        }
        //std::cout << left << ' ' << right << std::endl;
        if (std::tolower(A[left]) != std::tolower(A[right])) {
            return 0;
        }
        left++;
        right--;
    }
    return 1;
}

int main() {
    // abcda
    // std::string a = "aAbaa";
    std::string a = "A man, a plan, a canal: Panama";
    std::cout << is_palindrome(a);
}