#include <iostream>
#include <vector>
#include <unordered_map>

int count_at_most_k(std::vector<int> &A, int B) {
    int left = 0;
    int right = 0;
    int cnt = 0;
    std::unordered_map<int, int> unique;
    while (right < A.size()) {
        if (unique.find(A[right]) != unique.end()) {
            unique[A[right]]++;
        }
        else {
            unique[A[right]] = 1;
        }

        while (unique.size() > B) {
            unique[A[left]]--;
            if (unique[A[left]] == 0) {
                unique.erase(A[left]);
            }
            left++;
        }

        right++;
        cnt+= right - left;
    }
    return cnt;
}

int count_subarrays(std::vector<int> &A, int B) {
    return count_at_most_k(A, B) - count_at_most_k(A, B - 1);
}

int main() {
    std::vector<int> A = {1, 2, 1, 2, 3};
    int B = 2;
    std::cout << count_subarrays(A, B);
}