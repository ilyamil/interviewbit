#include <iostream>
#include <vector>

std::vector<int> intersection(const std::vector<int> &A,
                              const std::vector<int> &B)
{
    std::vector<int> inter = {};
    int a_ptr = 0;
    int b_ptr = 0;
    while (a_ptr < A.size() && b_ptr < B.size()) {
        if (A[a_ptr] == B[b_ptr]) {
            inter.push_back(A[a_ptr]);
            a_ptr++;
            b_ptr++;
        }
        else if (A[a_ptr] < B[b_ptr]) {
            a_ptr++;
        }
        else {
            b_ptr++;
        }
    }
    return inter;
}

int main() {
    // std::vector<int> A = {1, 2, 3, 3, 4, 5, 6};
    // std::vector<int> B = {3, 3, 5};
    // std::vector<int> A = {1, 2, 3, 3, 4, 5, 6};
    // std::vector<int> B = {3, 5};
    std::vector<int> A = {1, 2, 3, 3, 4, 5, 6};
    std::vector<int> B = {};
    for (auto el: intersection(A, B)) {
        std::cout << el << ' ';
    }
}