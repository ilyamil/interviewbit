#include <vector>
#include <iostream>
#include <math.h>
#include <unordered_set>
#include <unordered_map>

int find_duplicates(const std::vector<int> &A) {
    int N = A.size();
    int denominator = std::ceil(std::sqrt(N - 1));
    int target_bucket = -1;
    std::vector<int> buckets(denominator);
    for (int i = 0; i < A.size(); i++) {
        int bucket = int((A[i] - 1)/denominator);
        buckets[bucket]++;
        if (buckets[bucket] > denominator) {
            target_bucket = bucket;
            break;
        }
    }

    if (target_bucket == -1) {
        target_bucket = int((N - 2)/denominator);
    }

    std::unordered_set<int> unique;
    for (int i = 0; i < N; i++) {
        int cur_bucket = int((A[i] - 1) / denominator);
        if (cur_bucket == target_bucket) {
            if (unique.count(A[i]) == 0) {
                unique.insert(A[i]);
            }
            else {
                return A[i];
            }
        }
    }
    return -1;
}

int main() {
    //std::vector<int> A = {3, 4, 1, 4, 1};
    // std::vector<int> A = {3, 4, 1, 4, 1};
    //std::vector<int> A = {1, 3, 3, 3};
}