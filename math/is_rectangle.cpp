#include <iostream>

bool check_is_rectangle(int A, int B , int C, int D) {
    if (A == B) {
        return C == D;
    }
    if (B == C) {
        return A == D;
    }
    if (A == D) {
        return B == C;
    }
    return 0;
}

int main() {
    std::cout << check_is_rectangle(1, 1, 2, 2);
}