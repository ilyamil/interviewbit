#include <vector>
#include <iostream>
#include <unordered_map>

int find_pair(std::vector<int> &A, int B) {
    std::unordered_map<int, int> unique;
    for (auto el: A) {
        if (unique.find(el) != unique.end()) {
            unique[el]++;
        }
        else {
            unique[el] = 1;
        }
    }

    for (auto el: A) {
        bool first = unique.find(el - B) != unique.end();
        bool second = unique.find(el + B) != unique.end();
        if (first) {
            if (B == 0) {
                return unique[el - B] >= 2;
            }
            return 1;
        }
        else if (second) {
            if (B == 0) {
                return unique[el + B] >= 2;
            }
            return 1;
        }
    }
    return 0;
}

int main() {
    // std::vector<int> A = {5, 10, 3, 2, 50, 80};
    // int B = 78;
    // std::vector<int> A = {-10, 20};
    // int B = 30;
    std::vector<int> A = {20, 500, 1000, 200};
    int B = 0;
    std::cout << find_pair(A, B);
}