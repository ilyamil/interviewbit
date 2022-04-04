#include <vector>
#include <iostream>
#include <math.h>

int diffk(std::vector<int> &A, int B) {
    if (A.size() < 2) {
        return 0;
    }
    if (A.size() == 2) {
        return std::abs(A[0] - A[1]) == B? 1: 0;
    }

    int slow = 0;
    int fast = 1;
    while ((slow < A.size() - 1) && (fast <= A.size() - 1)) {
        if (slow == fast) {
            fast++;
        }
        int diff = A[fast] - A[slow];
        if (diff == B) {
            return 1;
        }
        else if (diff > B) {
            slow++;
        }
        else {
            fast++;
        }
    }
    return 0;
}

int main() {
    // std::vector<int> A = {1, 3, 5};
    // int B = 4;
    std::vector<int> A = {1, 2, 3, 100, 1999};
    int B = 1998;
    // {-8, -6, 0, 1, 2, 100}
    // std::vector<int> A = {1, 2, 2, 3, 4};
    // int B = 0;
    std::cout << diffk(A, B);
}