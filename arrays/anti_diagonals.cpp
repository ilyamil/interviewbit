#include <vector>
#include <iostream>

std::vector<std::vector<int>> create_anti_diag(std::vector<std::vector<int>> &A) {
    std::vector<std::vector<int>> anti_diag;
    int diag_num = 2 * (A.size() - 1) + 1;
    for (int order = 0; order < diag_num; order++) {
        anti_diag.push_back({});
        int i = order > diag_num / 2? order - diag_num / 2: 0;
        int j = order > diag_num / 2? diag_num / 2: order;
        int first_i = i;
        int first_j = j;
        while (i <= first_j && j >= first_i) {
            anti_diag[order].push_back(A[i][j]);
            i++;
            j--;
        }
    }
    return anti_diag;
}

int main() {
    // std::vector<std::vector<int>> A = {
    //     {1, 2, 3},
    //     {4, 5, 6},
    //     {7, 8, 9}
    // };
    // std::vector<std::vector<int>> A = {
    //     {1, 2},
    //     {3, 4}
    // };
    // std::vector<std::vector<int>> A = {{1}};
    std::vector<std::vector<int>> A = {};
    auto a = create_anti_diag(A);
    for (auto el: a) {
        for (auto s: el) {
            std::cout << s << ' ';
        }
        std::cout << std::endl;
    }
}