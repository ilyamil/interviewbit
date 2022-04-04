#include <vector>
#include <iostream>

std::vector<std::vector<int>> generate_pascal_triangle(int A) {
    if (A == 0) {
        return {};
    }
    if (A == 1) {
        return {{1}};
    }
    if (A == 2) {
        return {{1}, {1, 1}};
    }

    std::vector<std::vector<int>> triangle = {{1}, {1, 1}};
    for (int row_num = 3; row_num <= A; row_num++) {
        triangle.push_back(std::vector<int>(row_num, 1));
        for (int j = 1; j < row_num - 1; j++) {
            triangle[row_num - 1][j] = triangle[row_num - 2][j - 1] + triangle[row_num - 2][j];
        }
    }
    return triangle;
}

int main() {
    int A = 0;
    for (auto row: generate_pascal_triangle(A)) {
        for (auto col: row) {
            std::cout << col << ' ';
        }
        std::cout << std::endl;
    }
}