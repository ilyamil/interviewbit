#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

std::vector<int> get_updated_array(std::vector<int> &A) {
    std::unordered_map<int, int> indexes;
    for(int i = 0; i < A.size(); i++){
        if (indexes.find(A[i]) != indexes.end()){
            int last_idx = indexes[A[i]];
            A[last_idx]++;
            indexes[A[last_idx]] = last_idx;
        }
        indexes[A[i]] = i;
    }
    return A;
}

void print_vector(const std::vector<int> &A) {
    for (auto el: A) {
        std::cout << el << ' ';
    }
}

int main() {
    // std::vector<int> A = {1, 1, 1};
    // std::vector<int> A_inc = get_updated_array(A);
    // print_vector(A_inc);

    // std::vector<int> A = {1, 1, 2, 1};
    // std::vector<int> A_inc = get_updated_array(A);
    // print_vector(A_inc);

    // std::vector<int> A = {1, 2, 3, 4, 5};
    // std::vector<int> A_inc = get_updated_array(A);
    // print_vector(A_inc);

    std::vector<int> A = {1, 2, 3, 2, 3, 1, 4, 2, 1, 3};
    std::vector<int> A_inc = get_updated_array(A);
    print_vector(A_inc);
}