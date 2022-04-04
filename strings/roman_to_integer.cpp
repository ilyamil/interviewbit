#include <iostream>
#include <string>
#include <map>
#include <math.h>

std::map<std::string, int> ROMAN_TO_INT = {
    {"I", 1}, {"IV", 4}, {"V", 5}, {"IX", 9},
    {"X", 10}, {"XL", 40}, {"VL", 45}, {"IL", 49}, {"L", 50},
    {"XC", 90}, {"VC", 95}, {"IC", 99}, {"C", 100},
    {"CD", 400}, {"LD", 450}, {"XD", 490}, {"VD", 495}, {"ID", 499}, {"D", 500},
    {"CM", 900}, {"XM", 990}, {"VM", 995}, {"IM", 999}, {"M", 1000}
};


int convert_roman_to_int(std::string A) {
    int answer = 0;
    int pos = 0;
    while (pos < A.length()) {
        if (pos < A.length() - 1) {
            std::string substr = std::string(A.begin() + pos,
                                             A.begin() + pos + 2);
            if (ROMAN_TO_INT.find(substr) != ROMAN_TO_INT.end()) {
                answer += ROMAN_TO_INT[substr];
                pos += 2;
            }
            else {
                answer += ROMAN_TO_INT[std::string(1, A[pos])];
                char first_char = A[pos++];
                while (A[pos] == first_char) {
                    answer += ROMAN_TO_INT[std::string(1, A[pos])];
                    pos++;
                }
            }
        }
        else {
            answer += ROMAN_TO_INT[std::string(1, A[pos])];
            pos++;
        }
    }
    return answer;
}


int main() {
    std::string A = "XLI";
    // std::string A = "XXX";
    // std::string A = "XIV";
    std::cout << convert_roman_to_int(A);
}