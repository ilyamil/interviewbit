#include <iostream>
#include <vector>

void print_vector(std::vector<bool>& vec) {
    for (auto el: vec) {
        std::cout << el << ' ';
    }
    std::cout << std::endl;
}

int find_rightmost_idx(std::vector<int> &vec, int left, int right) {
    int rightmost_idx = -1;
    for (auto i = left; i <= right; i++) {
        if (vec[i] == 1) {
            rightmost_idx = i;
        }
    }
    return rightmost_idx;
}

int find_min_lights(std::vector<int> &A, int B) {
    int n = A.size();
    int num_lights = 0;
    int right = 0;
    for (int i = 0; i < A.size();) {
        right = find_rightmost_idx(A, std::max(0, i - B + 1),
                                   std::min(n - 1, i + B - 1));
        if (right == -1) {
            return -1;
        }
        num_lights++;
        i = right + B;
    }
    return num_lights;
}

int main() {
    std::vector<int> A = {0, 0, 1, 1, 1, 0, 0, 1};
    //std::vector<int> A = {0, 0, 0, 1, 0};
    //std::vector<int> A = {1, 1, 1, 1};
    std::cout << find_min_lights(A, 3);
    //std::vector<int> A = {1, 1, 1, 1, 1, 0, 0};
    //auto i = find_min_lights(A, 3);
    //std::cout << i;
}
