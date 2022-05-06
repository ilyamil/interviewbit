#include <vector>
#include <iostream>

std::vector<int> get_gray_code(int A) {
    std::vector<int> gray_code(1 << A);
    for (int i = 0; i < gray_code.size(); i++) {
        gray_code[i] = i ^ (i >> 1);
    }
    return gray_code;
}

int main() {
    int A = 2;
    std::vector<int> gray_code = get_gray_code(A);
    for (auto el: gray_code) {
        std::cout << el << ' ';
    }
}