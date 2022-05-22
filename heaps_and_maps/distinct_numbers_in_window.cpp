#include <iostream>
#include <map>
#include <vector>

std::vector<int> get_count(std::vector<int> &A, int B) {
    if (B > A.size()) {
        return {};
    }


    std::map<int, int> counter;
    int left = 0;
    int right = 0;
    while (right != B) {
        counter[A[right]]++;
        right++;
    }

    int nunique = counter.size();
    std::vector<int> answer = {nunique};
    while (right < A.size()) {
        if (counter[A[left]] > 1) {
            counter[A[left]]--;
        }
        else {
            counter.erase(A[left]);
        }
        counter[A[right]]++;
        left++;
        right++;

        nunique = counter.size();
        answer.push_back(nunique);
    }

    return answer;
}

int main() {
    // std::vector<int> A = {1, 2, 1, 3, 4, 3};
    // int B = 3;
    // auto ans = get_count(A, B);

    std::vector<int> A = {1, 1, 2, 2};
    int B = 1;
    auto ans = get_count(A, B);

    for (auto el: ans) {
        std::cout << el << ' ';
    }
}