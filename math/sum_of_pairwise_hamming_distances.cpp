#include <iostream>
#include <vector>

int sum_distances(const std::vector<int> &A) {
    int total_cnt = 0;
    for (int bit_pos = 0; bit_pos < 32; bit_pos++) {
        int cnt = 0;
        for (int i = 0; i < A.size(); i++) {
            cnt += (A[i] >> bit_pos) & 1;
        }
        total_cnt += cnt*(A.size() - cnt);
    }
    return total_cnt % 1000000007;
}

int main() {
    int a = 1;
    int b = 3;
    std::cout << (b << 1) << std::endl;
    std::cout << (a&b);
}