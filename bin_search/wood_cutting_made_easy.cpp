#include <vector>
#include <iostream>

int max_height(std::vector<int> &A, int B) {
    int bot = 0;
    int top = -1;
    for (auto el: A) {
        top = std::max(top, el);
    }
    int mid = (bot + top) / 2;
    while (bot <= top) {
        long long volume = 0;
        for (auto el: A) {
            volume += std::max(0, el - mid);
        }
        if (volume >= B) {
            bot = mid + 1;
        }
        else {
            top = mid - 1;
        }
        mid = (bot + top) / 2;
    }
    return mid;
}

int main() {
    std::vector<int> A = {20, 15, 10, 17};
    std::cout << max_height(A, 7);
}