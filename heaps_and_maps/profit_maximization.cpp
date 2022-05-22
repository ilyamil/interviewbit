#include <iostream>
#include <vector>
#include <queue>

int get_max_profit(std::vector<int> &A, int B) {
    std::priority_queue<int> pq(A.begin(), A.end());

    int profit = 0;
    while (B != 0) {
        int top = pq.top();
        pq.pop();
        profit += top;
        top--;
        pq.push(top);
        B--;
    }
    return profit;
}

int main() {
    std::vector<int> A = {2, 3};
    int B = 3;
    std::cout << get_max_profit(A, B);
}