#include <vector>
#include <iostream>

int count_moves(int A, int B) {
    int cnt = 0;
    // bottom right
    cnt += std::min(8 - A, B - 1);
    // bottom left
    cnt += std::min(A - 1, B - 1);
    // top right
    cnt += std::min(8 - A, 8 - B);
    // top left
    cnt += std::min(A - 1, 8 - B);
    return cnt;
}

int main() {
    auto i = count_moves(4, 4);
    std::cout << i;
}