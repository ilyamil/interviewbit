#include <vector>
#include <iostream>

int get_single_number(const std::vector<int> &A) {
    int answer = 0;
    for (auto el: A) {
        answer ^= el;
    }
    return answer;
}

int main() {
    std::vector<int> A = {1, 2, 1, 3, 2, 3, 5};
    std::cout << get_single_number(A);
}