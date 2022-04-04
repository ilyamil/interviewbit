#include <vector>
#include <iostream>

std::vector<std::vector<int>> generate_spiral_matrix(int A) {
    std::vector<std::vector<int>> result(A, std::vector<int>(A));
    int cnt = 1;
    for (int layer = 0; layer < (A + 1) / 2; layer++) {
        for (int ptr = layer; ptr < A - layer; ptr++) {
            result[layer][ptr] = cnt;
            cnt++;
        }
        for (int ptr = layer + 1; ptr < A - layer; ptr++) {
            result[ptr][A - layer - 1] = cnt;
            cnt++;
        }
        for (int ptr = A - layer - 2; ptr >= layer; ptr--) {
            result[A - layer - 1][ptr] = cnt;
            cnt++;
        }
        for (int ptr = A - layer - 2; ptr > layer; ptr--) {
            result[ptr][layer] = cnt;
            cnt++;
        }
    }
    return result;
}

int main() {
    int n = 4;
    for (auto row: generate_spiral_matrix(n)) {
        for (auto col: row) {
            std::cout << col << ' ';
        }
        std::cout << "\n";
    }
}