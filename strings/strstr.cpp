#include <string>
#include <iostream>

int str_str(const std::string A, const std::string B) {
    if (B.length() == 0 || A.length() == 0
        || B.length() > A.length()) {
        return -1;
    }

    if (A.length() == B.length()) {
        return A == B? 0: -1;
    }

    int idx = 0;
    while (idx <= (A.length() - B.length())) {
        if (A[idx] == B[0]) {
            int needle_idx = 0;
            int haystack_idx = idx;
            while (needle_idx < B.length()
                    && A[idx] == B[needle_idx]) {
                needle_idx++;
                idx++;
            }
            if (needle_idx == B.length()) {
                return haystack_idx;
            }
            idx = haystack_idx;
        }
        idx += 1;
    }
    return -1;
}


int main() {
    // std::string A = "abcbcd";
    // std::string B = "cd";
    // std::string A = "aaacb";
    // std::string B = "cd";
    // std::string A = "cb";
    // std::string B = "cd";
    // std::string A = "aaacdaaa";
    // std::string B = "cd";
    // std::string A = "babaaaabbbbbabbaababbaaabbabaaaabaaaabbaabaabababaabbaabbaaaaababba";
    // std::string B = "bbaa";
    std::string A = "aabaaaababaabbbabbabbbaabababaaaaaababaaabbabbabbabbaaaabbbbbbaabbabbbbbabababbaaabbaabbbababbb";
    std::string B = "bba";

    std::cout << str_str(A, B);
}