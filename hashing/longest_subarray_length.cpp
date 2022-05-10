#include <iostream>
#include <vector>
#include <unordered_map>

int get_longest_subarray_length(std::vector<int> &A) {
    std::unordered_map<int, int> sums;
    int sum = 0;
    int output_length = 0;
    for (int i = 0; i < A.size(); i++) {
        if(A[i] == 0) {
            sum += -1;
        }
        else {
            sum += 1;
        }

        if (sum == 1) {
            output_length = i + 1;
        }
        else if (sums.find(sum) == sums.end()) {
            sums[sum] = i;
        }
        if (sums.find(sum - 1) != sums.end()
            && output_length < (i - sums[sum - 1])) {
            output_length = i - sums[sum - 1];
        }
    }
    return output_length;
}

int main() {
    // 0, 1, 1, 0, 0, 1
}