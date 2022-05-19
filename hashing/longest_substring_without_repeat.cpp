#include <string>
#include <iostream>
#include <unordered_map>

int get_length(std::string A) {
    std::unordered_map<char, int> chars;
    int len = 0;
    int slow = 0;
    int fast = 0;
    while (fast != A.size()) {
        if (chars.find(A[fast]) != chars.end() && chars[A[fast]] >= slow) {
            slow = chars[A[fast]] + 1;
        }
        chars[A[fast]] = fast;
        fast++;
        len = std::max(len, fast - slow);
    }
    return len;
}

int main() {
    // std::string A = "abcabcbb"; // abc
    // std::cout << get_length(A);

    // std::string A = "bbb"; // abc
    // std::cout << get_length(A);

    // std::string A = "bbbabbb"; // abc
    // std::cout << get_length(A);

    std::string A = "bababac"; // abc
    std::cout << get_length(A);
}