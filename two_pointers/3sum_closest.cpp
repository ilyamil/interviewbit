#include <vector>
#include <iostream>
#include <algorithm>


int three_sum(std::vector<int> &A, int B) {
    std::sort(A.begin(), A.end());
    
    int N = A.size() - 1;
    int closest_sum = A[N] + A[N - 1] + A[N - 2];
    for (int i = 0; i < N - 2; i++) {
        int left = i + 1;
        int right = N;
        int cur_sum = A[i] + A[left] + A[right];
        while (left < right) {
            std::cout << cur_sum << std::endl;
            if (cur_sum == B) {
                return B;
            }
            std::cout << std::abs(cur_sum - B) << " " << std::abs(closest_sum - B) << std::endl;
            if (std::abs(cur_sum - B) < std::abs(closest_sum - B)) {
                std::cout << "HERE!\n";
                closest_sum = cur_sum;
            }
            else if (cur_sum > B) {
                right--;
            }
            else {
                left++;
            }
            cur_sum = A[i] + A[left] + A[right];
        }
    }
    return closest_sum;
}


int main() {
    // std::vector<int> A = {-1, 2, 1, -4};
    // int B = 1;
    std::vector<int> A = {2, 1, -9, -7, -8, 2, -8, 2, 3, -8};
    int B = -1;
    std::cout << three_sum(A, B);
}