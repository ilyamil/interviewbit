#include <iostream>
#include <vector>

void print_vector(std::vector<int> A) {
    for (auto el: A) {
        std::cout << el << ' ';
    }
    std::cout << std::endl;
}


int count_subarrays(std::vector<int> &A, int B) {
    int cnt = 0;
    int slow = 0;
    int fast = 0;
    int sum = A[slow];
    while (slow < A.size() && fast < A.size()) {
        if (sum < B) {
            fast++;
            if (fast >= slow) {
                cnt += (fast - slow);
            }
            if (fast < A.size()) {
                sum += A[fast];
            }
        }
        else {
            sum -= A[slow];
            slow++;
        }
    }
    return cnt;
}

int main() {
    std::vector<int> A = {1, 11, 2, 3, 15, 1};
    int B = 10;
    auto i = count_subarrays(A, B);
}