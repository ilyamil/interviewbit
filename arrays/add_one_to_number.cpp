#include <iostream>
#include <vector>

std::vector<int> reverse(std::vector<int> &orig) {
    int N = orig.size();
    std::vector<int> reversed(N);
    for (auto i = N - 1; i >= 0; i--) {
        reversed[N - i - 1] = orig[i];
    }
    return reversed;
}

std::vector<int> add_one(std::vector<int> &A) {
    int N = A.size();
    int sign_digit = N - 1;
    for (auto i = 0; i < N - 1; i++) {
        if (A[i] != 0) {
            sign_digit = i;
            break;
        }
    }

    int resid = 1;
    int sum = 0;
    std::vector<int> reverse_ans;
    for (int i = N - 1; i >= sign_digit; i--) {
        sum = resid + A[i];
        reverse_ans.push_back(sum % 10);
        resid = sum / 10;
    }

    if (resid == 1) {
        reverse_ans.push_back(resid);
    }

    return reverse(reverse_ans);
}

int main() {
    std::vector<int> A = {0, 1, 2, 3};
    auto res = add_one(A);
    for (auto el: res) {
        std::cout << el << ' ';
    }
}