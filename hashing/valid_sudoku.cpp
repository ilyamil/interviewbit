#include <vector>
#include <string>
#include <iostream>
#include <unordered_set>

int check_horizontal_consistency(const std::vector<std::string> &sudoku) {
    for (const std::string &row: sudoku) {
        std::unordered_set<int> unique;
        for (char number: row) {
            if (number != '.') {
                if (unique.count(number)) {
                    return 0;
                }
                unique.insert(number);
            }
        }
    }
    return 1;
}

int check_vertical_consistency(const std::vector<std::string> &sudoku) {
    for (int i = 0; i < sudoku.size(); i++) {
        std::unordered_set<int> unique;
        for (const std::string &row: sudoku) {
            if (row[i] != '.') {
                if (unique.count(row[i] - 'a')) {
                    return 0;
                }
                unique.insert(row[i] - 'a');
            }
        }
    }
    return 1;
}

int check_box(const std::vector<std::string> &sudoku) {
    for (int row_num = 0; row_num < 9; row_num += 3) {
        for (int col_num = 0; col_num < 9; col_num += 3) {
            std::unordered_set<int> unique;
            for (int i = row_num; i < row_num + 3; i++) {
                for (int j = col_num; j < col_num + 3; j++) {
                    if (sudoku[i][j] != '.') {
                        if (unique.count(sudoku[i][j] - 'a')) {
                            return 0;
                        }
                        unique.insert(sudoku[i][j] - 'a');
                    }
                }
            }
        }
    }
    return 1;
}

int check_sudoku_validity(const std::vector<std::string> &A) {
    return check_horizontal_consistency(A)
            && check_vertical_consistency(A)
            && check_box(A);
}

int main() {
    std::vector<std::string> A = {
        "53..7....", "6..195...", ".98....6.",
        "8...6...3", "4..8.3..1", "7...2...6",
        ".6....28.", "...419..5", "....8..79"
    };

    std::cout << check_sudoku_validity(A);
}