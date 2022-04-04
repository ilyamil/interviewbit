#include <iostream>
#include <string>
#include <map>

std::map<char, int> NUMBERS = {
    {'1', 1},
    {'2', 2},
    {'3', 3},
    {'4', 4},
    {'5', 5},
    {'6', 6},
    {'7', 7},
    {'8', 8},
    {'9', 9},
    {'0', 0}
};

bool is_number(char c) {
    return NUMBERS.find(c) != NUMBERS.end();
}

int atoi(std::string A) {
    bool negative = 0;
    int spaces = 0;
    int answer = 0;
    for (int i = 0; i < A.length(); i++) {
        if (i == 0 && A[i] == '-') {
            negative = 1;
        }
        else if (i == 0 && A[i] == '+') {
            negative = 0;
        }
        else if(answer == 0 && A[i] == ' ' && i == spaces) {
                spaces++;
                continue;
        }
        else if (A[i] == ' ') {
            break;
        }
        else if (!is_number(A[i])) {
            break;
        }
        else if (is_number(A[i])) {
            int num = NUMBERS[A[i]];
            if (answer > (INT32_MAX - num) / 10) {
                return negative? INT32_MIN: INT32_MAX;
            }
            answer = answer * 10 + num;
        }
    }
    return negative? -answer: answer;
}

int main() {
    // std::string A = "1 0";
    // std::string A = "-1";
    // std::string A = "-1ac";
    // std::string A = "-abc";
    // std::string A = "2147483647";
    // std::string A = "2147483647000";
    // std::string A = "-2147483648";
    // std::string A = "9 2704";
    // std::string A = " 9 2704";
    //std::string A = "- 5 88C340185Q 71 8079 834617385 2898422X5297Z6900";
    //std::string A = "V515V 5793K 627 23815945269 1 1249794L 631 8755 7";
    //std::string A = "+ 3611156";
    std::string A = "+7";
    std::cout << atoi(A);
}