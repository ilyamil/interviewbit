#include <iostream>
#include <string>
#include <vector>

bool is_vowel(char c) {
    return (c == 'a') || (c == 'e') || (c == 'i')
            || (c == 'o') || (c == 'u');
}

int count(std::string A) {
    int vowel_cnt = 0;
    int consonant_cnt = 0;
    for (int i = 0; i < A.length(); i++) {
        if (is_vowel(A[i])) {
            vowel_cnt++;
        }
        else {
            consonant_cnt++;
        }
    }

    int cnt = 0;
    for (int i = 0; i < A.length(); i++) {
        if (is_vowel(A[i])) {
            cnt += consonant_cnt;
            vowel_cnt--;
        }
        else {
            cnt += vowel_cnt;
            consonant_cnt--;
        }
    }

    return cnt % int(1e9 + 7);
}

int main() {
    std::string A = "abacd";
    auto i = count(A);
}