#include <string>
#include <iostream>
#include <map>
#include <math.h>

std::map<char, int> ROMAN_NUMBERS {
    {1, 'I'}, {5, 'V'},
    {10, 'X'}, {50, 'L'},
    {100, 'C'}, {500, 'D'},
    {1000, 'M'}
};

std::string convert_int_to_roman(int A) {
    std::string roman = "";
    int order = 0;
    while (A != 0) {
        int num = A % 10;
        if ((num >= 1) && (num <= 3)) {
            for (int i = 1; i <= num; i++) {
                roman += ROMAN_NUMBERS[1 * std::pow(10, order)];
            }
        }
        if (num == 4) {
            roman += ROMAN_NUMBERS[5 * std::pow(10, order)];
            roman += ROMAN_NUMBERS[1 * std::pow(10, order)];
        }
        if ((num >= 5) && (num <= 8)) {
            for (int i = 6; i <= num; i++) {
                roman += ROMAN_NUMBERS[1 * std::pow(10, order)];
            }
            roman += ROMAN_NUMBERS[5 * std::pow(10, order)];
        }
        if (num == 9) {
            roman += ROMAN_NUMBERS[1 * std::pow(10, order + 1)];
            roman += ROMAN_NUMBERS[1 * std::pow(10, order)];
        }
        A /= 10;
        order++;
    }
    return std::string(roman.rbegin(), roman.rend());
}

int main() {
    // 153 = 100 + 50 + 3 = CLIII
    // 249 = 200 + 40 + 9 = CCXLIX
    // 1365 = 1000 + 300 + 60 + 5 = MCCCLXV
    // X, XX, XXX, XL, L, LX, LXX, LXXX, XC, 
    // int A = 153;
    // int A = 1365;
    // int A = 4;
    int A = 9;
    std::cout << convert_int_to_roman(A);
}