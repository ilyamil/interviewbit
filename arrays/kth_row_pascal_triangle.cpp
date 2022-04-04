#include <vector>
#include <iostream>

int calc_factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * calc_factorial(n - 1);
}

int calc_binomial_coef(int n, int m) {
    return calc_factorial(n) / calc_factorial(m) / calc_factorial(n - m);
}

// std::vector<int> get_row(int A) {
//     std::vector<int> row(A + 1);
//     for (int i = 0; i <= A; i++) {
//         row[i] = calc_binomial_coef(A, i);
//     }
//     return row;
// }

std::vector<int> get_row(int A) {
    if (A == 0) {
        return {1};
    }
    if (A == 1) {
        return {1, 1};
    }

    std::vector<int> prev_row = {1, 1};
    std::vector<int> cur_row;
    for (int i = 2; i <= A; i++) {
        cur_row = std::vector<int>(i + 1, 1);
        for (int j = 1; j < i; j++) {
            cur_row[j] = prev_row[j - 1] + prev_row[j];
        }
        prev_row = cur_row;
    }
    return cur_row;
}

int main() {
    for (auto el: get_row(25)) {
        std::cout << el << ' ';
    }
    // for (auto el: get_row(15)) {
    //     std::cout << el << ' ';
    // }
}