#include <iostream>
#include <vector>

void sort_by_color(std::vector<int> &A) {
    std::vector<int> cnt({0, 0, 0});
    for (auto el: A) {
        cnt[el]++;
    }

    int pos = 0;
    while (cnt[0] != 0) {
        A[pos++] = 0;
        cnt[0]--;
    }
    while (cnt[1] != 0) {
        A[pos++] = 1;
        cnt[1]--;
    }
    while (cnt[2] != 0) {
        A[pos++] = 2;
        cnt[2]--;
    }
}

int main() {
    std::vector<int> A = {0, 1, 2, 0, 1, 2};
    sort_by_color(A);
    for (auto el: A) {
        std::cout << el << ' ';
    }
}