#include <iostream>

int get_number_of_ones(unsigned int A) {
    unsigned int cnt = 0;
    while (A != 0) {
        if (A & 1) {
            cnt++;
        }
        A >>= 1;
    }
    return cnt;
}

int main() {
    unsigned A = 4;
    std::cout << get_number_of_ones(A);
}