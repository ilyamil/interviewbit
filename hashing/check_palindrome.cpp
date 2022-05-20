#include <iostream>
#include <string>
#include <unordered_map>

int check_palindrome(std::string A) {
    std::unordered_map<int, int> counter;
    for (char c: A) {
        counter[c - 'a'] += 1;
    }
    
    int odd_cnt = 0;
    for (auto p: counter) {
        if (p.second % 2 == 1) {
            odd_cnt++;
        }
    }

    if ((A.length() % 2 == 0 && odd_cnt == 0)
        || (A.length() % 2 == 1 && odd_cnt == 1)) {
        return 1;
    }
    return 0;
}

int main() {
    std::string A = "abcba";
    std::cout << check_palindrome(A);
}