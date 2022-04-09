#include <iostream>

unsigned int reverse_bits(unsigned int A) {
    unsigned int answer = 0;
    for (int i = 31; i >= 0; i--) {
        if ((A & 1)) {
            answer += (1 << i);
        }
        A >>= 1;
    }
    return answer;
}

int main() {
    // 000000001 -> 100000000
    // 101000001 -> 100000101
    unsigned int i = 3;
    std::cout << reverse_bits(i);
}