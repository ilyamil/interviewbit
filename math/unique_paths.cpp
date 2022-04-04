#include <vector>
#include <iostream>

int find_unique_paths(int A, int B) {
    std::vector<std::vector<int>> grid(A, std::vector<int>(B, 0));
    for (int row_num = 0; row_num < A; row_num++) {
        for (int col_num = 0; col_num < B; col_num++) {
            if (row_num == 0 || col_num == 0) {
                grid[row_num][col_num] = 1;
            }
            else {
                grid[row_num][col_num] = grid[row_num - 1][col_num]
                    + grid[row_num][col_num - 1];
            }
        }
    }
    for (auto row: grid) {
        for (auto col: row) {
            std::cout << col << ' ';
        }
        std::cout << std::endl;
    }

    return grid[A - 1][B - 1];
}

int main() {
    auto i = find_unique_paths(2, 2);
}