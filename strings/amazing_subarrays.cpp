#include <string>
#include <iostream>
#include <set>


bool is_vowel(char c) {
    std::set<char> vowel_letters = {
        'a', 'e', 'i', 'o', 'u',
        'A', 'E', 'I', 'O', 'U'
    };
    return vowel_letters.find(c) != vowel_letters.end();
}


int count_substrings(std::string A) {
    int cnt = 0;
    int N = A.length();
    for (int i = 0; i < N; i++) {
        if (is_vowel(A[i])) {
            cnt += (N - i);
        }
    }
    return cnt % 10003;
}

int main() {
    std::string a = "ABEC";
    std::string A = "BBBQ";
    std::cout << count_substrings(A);
}