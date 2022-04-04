#include <vector>
#include <iostream>
#include <algorithm>

int find_max_distance(const std::vector<int> &A) {
    int N = A.size();
    std::vector<std::pair<int, int>> el_idx(N);
    for (int i = 0; i < N; i++) {
        el_idx[i] = std::make_pair(A[i], i);
    }
    std::sort(el_idx.begin(), el_idx.end());

    int max_dist = 0;
    int rmax = el_idx[N - 1].second;
    for(int i = N - 2; i >= 0; i--){
        max_dist = std::max(max_dist, rmax - el_idx[i].second);
        rmax = std::max(rmax, el_idx[i].second);
    }
    return max_dist;
}

int main() {
    std::vector<int> A = {3, 5, 4, 2};
    std::cout << find_max_distance(A);
}