#include <iostream>
#include <vector>

int reverse(int A) {
    bool is_positive = A < 0? 0: 1;
    A = std::max(A, -A);

    int B = 0;
    while (A != 0) {
        B = B * 10 + A % 10;
        if (B > (INT32_MAX / 10) && A / 10 != 0) {
            return 0;
        }
        A /= 10;
    }
    return is_positive? B: -B;
}

int main() {
    std::vector<int> tests = {
        123, 0, 5, 10, 12, -1, -10, -123, 2147483647, -1234567891
    };
    for (auto test: tests) {
        std::cout << test << ' ' << reverse(test) << std::endl;;
    }
}