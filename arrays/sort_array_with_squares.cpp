#include <iostream>
#include <vector>

std::vector<int> sort_squares(std::vector<int> &A) {
    int N = A.size();
    std::vector<int> squares(N);
    int left = 0;
    int right = N - 1;
    for (int i = N - 1; i >= 0; i--) {
        if (std::abs(A[right]) >= std::abs(A[left])) {
            squares[i] = A[right] * A[right];
            right--;
        }
        else {
            squares[i] = A[left] * A[left];
            left++;
        }
    }
    return squares;
}

int main() {
    std::vector<int> A = {-5, -4, -2, 0, 1};
    for (auto el: sort_squares(A)) {
        std::cout << el << ' ';
    }
}