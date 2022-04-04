#include <iostream>

int distribute(int A, int B, int C) {
    int pos = C;
    while (A >= 2) {
        pos = (pos + 1) % B;
        A--;
    }
    return pos;
}

int main() {
    // int A = 2;
    // int B = 5;
    // int C = 1;
    int A = 8;
    int B = 5;
    int C = 2;
    std::cout << distribute(A, B, C);
}