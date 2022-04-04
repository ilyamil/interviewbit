#include <iostream>

int gcd(int A, int B) {
    if (A == 0 || B == 0) {
        return std::max(A, B);
    }

    while (A != B) {
        if (A > B) {
            A -= B;
        }
        else {
            B -= A;
        }
    }
    return A;
}

int main() {
    std::cout << gcd(0, 18);
}