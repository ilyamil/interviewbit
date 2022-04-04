#include <iostream>

long long factorial(int A) {
    if (A == 1) {
        return 1;
    }
    return factorial(A - 1) * A;
}

int get_trailing_zeroes(int A) {
    return A == 0 ? 0 : A / 5 + get_trailing_zeroes(A / 5);
}
int main() {
    int A = 20;
    std::cout << get_trailing_zeroes(A);
}