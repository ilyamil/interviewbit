#include <vector>
#include <iostream>

void mark(std::vector<std::vector<int>> &A, int row, int col) {
    if (A[0][col] != -1) {
        A[0][col] = -1;
    }
    if (A[row][0] != -1) {
        A[row][0] = -1;
    }
}

void set_zeros(std::vector<std::vector<int>> &A) {
    bool row_zero = 0;
    bool col_zero = 0;
    for (auto row_num = 0; row_num < A.size(); row_num++) {
        if (A[row_num][0] == 0) {
            col_zero = 1;
        }
    }
    for (auto col_num = 0; col_num < A[0].size(); col_num++) {
        if (A[0][col_num] == 0) {
            row_zero = 1;
        }
    }

    for (auto row_num = 1; row_num < A.size(); row_num++) {
        for (auto col_num = 1; col_num < A[row_num].size(); col_num++) {
            if (A[row_num][col_num] == 0) {
                A[row_num][0] = 0;
                A[0][col_num] = 0;
            }
        }
    }
    for (auto row_num = 1; row_num < A.size(); row_num++) {
        for (auto col_num = 1; col_num < A[row_num].size(); col_num++) {
            if (A[row_num][0] == 0 || A[0][col_num] == 0) {
                A[row_num][col_num] = 0;
            }
        }
    }

    if (row_zero) {
        for (auto col_num = 0; col_num < A[0].size(); col_num++) {
            A[0][col_num] = 0;
        }
    }
    if (col_zero) {
        for (auto row_num = 0; row_num < A.size(); row_num++) {
            A[row_num][0] = 0;
        }        
    }
}

int main() {
    std::vector<std::vector<int>> A = {
        {1, 0, 1},
        {1, 0, 1},
        {1, 1, 1}
    };
    // std::vector<std::vector<int>> A = {
    //     {1, 0, 1},
    //     {0, 1, 1},
    //     {1, 1, 1}
    // };
    // std::vector<std::vector<int>> A = {
    //     {0, 0},
    //     {1, 1}
    // };
    // std::vector<std::vector<int>> A = {
    //     {0, 0},
    //     {1, 0}
    // };
    set_zeros(A);
    for (auto rows: A) {
        for (auto col: rows) {
            std::cout << col << ' ';
        }
        std::cout << std::endl;
    }
}