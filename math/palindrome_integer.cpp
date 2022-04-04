#include <iostream>

bool check_is_palindrome(int A) {
    if(A < 0 || (A % 10 == 0 && A != 0)) {
        return false;
    }

    int revertedNumber = 0;
    while(A > revertedNumber) {
        revertedNumber = revertedNumber * 10 + A % 10;
        A /= 10;
    }
    return A == revertedNumber || A == revertedNumber/10;
}

int main() {
    int A = 12321;
    auto i = check_is_palindrome(10);
}