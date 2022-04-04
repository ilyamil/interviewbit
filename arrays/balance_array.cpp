#include <vector>
#include <iostream>

int check_balance(std::vector<int> &A) {
    int N = A.size();

    int even = 0;
    int odd = 0;
    std::vector<int> left_even(N);
    std::vector<int> left_odd(N);
    for (int i = 0; i < N; i++) {
        left_even[i] = even;
        left_odd[i] = odd;
        if (i % 2 == 0) {
            even += A[i];
        } 
        else {
            odd += A[i];
        }
    }

    even = 0;
    odd = 0;
    std::vector<int> right_even(N);
    std::vector<int> right_odd(N);
    for (int i = N - 1; i >= 0; i--) {
        right_even[i] = even;
        right_odd[i] = odd;
        if (i % 2 == 0) {
            even += A[i];
        }
        else {
            odd += A[i];
        }
    }


    int cnt = 0;
    for (int i = 0; i < N; i++) {
        if (left_even[i] + right_odd[i] == left_odd[i] + right_even[i]) {
            cnt++;
        }
    }
    std::cout << "Left even\n";
    for (auto el: left_even) {
        std::cout << el << ' ';
    }
    std::cout << "\nLeft odd\n";
    for (auto el: left_odd) {
        std::cout << el << ' ';
    }
    std::cout << "\nRight even\n";
    for (auto el: right_even) {
        std::cout << el << ' ';
    }
    std::cout << "\nRight odd\n";
    for (auto el: right_odd) {
        std::cout << el << ' ';
    }
    return cnt;
}

int main() {
    std::vector<int> A = {2, 1, 6, 4};
    auto i = check_balance(A);
    std::cout << std::endl << i;
}