#include <iostream>
#include <queue>
#include <string>
#include <vector>

std::string get_nonrepeating_string(std::string A) {
    std::vector<int> counter(26, 0);
    std::queue<int> q;
    std::string answer;
    for (auto c: A) {
        counter[c - 'a'] += 1;
        q.push(c);

        while (!q.empty()) {
            if (counter[q.front() - 'a'] >= 2) {
                q.pop();
            }
            else {
                answer += q.front();
                break;
            }
        }

        if (q.empty()) {
            answer += "#";
        }
    }
    return answer;
}

int main() {
    std::string A = "abadbc";
    std::cout << get_nonrepeating_string(A);
}