#include <iostream>

int get_trailing_zeroes(int A) {
    int cnt = 0;
    while (!(A & 1)) {
        cnt++;
        A >>= 1;
    }
    return cnt;
}

int main() {
    // int 4 = 00000100
    int A = 8;
    std::cout << get_trailing_zeroes(A);
}