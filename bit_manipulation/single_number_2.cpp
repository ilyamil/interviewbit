#include <iostream>
#include <vector>
#include <cmath>

int get_single_number(const std::vector<int> &A) {
    std::vector<int> bit_cnt(32, 0);
    for (int i = 0; i < A.size(); i++) {
        int n = A[i];
    	for (int j = 31; j >= 0; --j) {
    		bit_cnt[j] += n & 1;
    		n >>= 1;
    		if (!n) {
                break;
            }
    	}
    }

    for (auto el: bit_cnt) {
        std::cout << el << ' ';
    }
    std::cout << std::endl;

    int answer = 0;
    for (int i = 0; i < bit_cnt.size(); i++) {
        if (bit_cnt[i] % 3 > 0) {
			answer += 1 << (31 - i);
        }
    }
    return answer;
}

int main() {
    // 0011 0011 0011 -> 1100 0011 0011
    // 0011 0011 0011 -> 
    // A = {0001, 0010, 0010, 0001, 0011, 0001, 0010}
    // 0001 0111 
    // A+ = 1101
    std::vector<int> A = {1, 1, 1, 3, 2, 3, 3};
    std::cout <<  get_single_number(A);
    // int A = 3;
    // std::cout << (A ^ (~A) & A);
}