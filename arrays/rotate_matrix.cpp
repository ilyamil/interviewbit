#include <iostream>
#include <vector>

void print_matrix(const std::vector<std::vector<int>> &v) {
    for (int row_num = 0; row_num < v.size(); row_num++) {
        for (int col_num = 0; col_num < v[row_num].size(); col_num++) {
            std::cout << v[row_num][col_num] << ' ';
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void transpose(std::vector<std::vector<int>> &A) {
    size_t N = A.size();
    for (size_t i = 0; i < N; i++) {
        for (size_t j = i + 1; j < N; j++) {
            int tmp = A[i][j];
            A[i][j] = A[j][i];
            A[j][i] = tmp;
        }
    }
}

void reflect(std::vector<std::vector<int>> &A) {
    size_t N = A.size();
    for (size_t i = 0; i < N; i++) {
        for (size_t j = 0; j < (N + 1) / 2; j++) {
            int tmp = A[i][j];
            A[i][j] = A[i][N - j - 1];
            A[i][N - j - 1] = tmp;
        }
    }    
}

void rotate(std::vector<std::vector<int>> &A) {
    transpose(A);
    reflect(A);
}

int main() {
    std::vector<std::vector<int>> A = {
        {1, 2},
        {3, 4}
    };
    // std::vector<std::vector<int>> A = {
    //     {1, 2, 3},
    //     {4, 5, 6},
    //     {7, 8, 9}
    // };
    print_matrix(A);
    rotate(A);
    print_matrix(A);
}