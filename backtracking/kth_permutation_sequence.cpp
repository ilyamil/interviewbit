#include <vector>
#include <iostream>
#include <string>

std::vector<int> calc_factorial(int k) {
    std::vector<int> factorial(k + 1, 1);
    for (int i = 1; i <= k; i++) {
        if (i > 12) {
            factorial[i] = INT32_MAX;
        }
        else {
            factorial[i] = factorial[i - 1] * i;
        }
    }
    return factorial;
}

std::string get_kth_sequence(int A, int B) {
    std::string answer = "";
    std::vector<int> factorial = calc_factorial(A);

    if (B == 1) {
        for (int i = 0; i < A; i++) {
            answer += std::to_string(i + 1);
        }
        return answer;
    }

    std::vector<int> indexes(A);
    for (auto i = 0; i < A; i++) {
        indexes[i] = i + 1;
    }

    while (A > 0) {
        int idx = (B - 1) / factorial[A - 1];
        B -= factorial[A - 1] * idx;
        answer += std::to_string(indexes[idx]);
        indexes.erase(indexes.begin() + idx);
        A--;
    }
    return answer;
}

int main() {
    int N = 3;
    int K = 1;
    std::cout << get_kth_sequence(N, K);
}