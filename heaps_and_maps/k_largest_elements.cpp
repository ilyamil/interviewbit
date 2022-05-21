#include <iostream>
#include <vector>
#include <queue>

std::vector<int> get_k_largest(std::vector<int> &A, int B) {
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    for (auto el: A) {
        pq.push(el);
        if (pq.size() > B) {
            pq.pop();
        }
    }

    std::vector<int> answer;
    while (!pq.empty()) {
        answer.push_back(pq.top());
        pq.pop();
    }
    return answer;
}

int main() {
    std::vector<int> A = {11, 3, 4, 6};
    int B = 3;
    std::vector<int> ans = get_k_largest(A, B);
    for (auto el: ans) {
        std::cout << el << ' ';
    }
}