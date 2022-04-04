#include <iostream>
#include <vector>
#include <set>

int find_max_sum_triplet(std::vector<int> &A) {
    int max_sum = 0;
    int n = A.size();

    std::vector<int> suffix(n);
    for (int i = n - 1; i >= 0; i--) {
        suffix[i] = std::max(suffix[std::min(i + 1, n - 1)], A[i]);
    }

    std::set<int> prefix = {A[0]};

    for (int i = 1; i < n - 1; i++) {
        prefix.insert(A[i]);

        if (A[i] >= suffix[i]){
            continue;
        }

        auto it = prefix.lower_bound(A[i]);
        if (it != prefix.begin()) {
            it--;
            max_sum = std::max(max_sum, *it + A[i] + suffix[i]);
        }
    }
    return max_sum;
}

int main() {
    std::vector<int> A = {2, 5, 3, 1, 4, 9};
    std::cout << find_max_sum_triplet(A);
}