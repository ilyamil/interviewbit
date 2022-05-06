#include <iostream>
#include <string>
#include <math.h>

void find_max(std::string orig, std::string &ans, int k) {
    if (k == 0) {
        return;
    }

    for (int i = 0; i < orig.size() - 1; i++) {
        for (int j = i + 1; j < orig.size(); j++) {
            if (orig[i] < orig[j]) {
                std::swap(orig[i], orig[j]);
                ans = std::max(orig, ans);
                find_max(orig, ans, k - 1);
                std::swap(orig[i], orig[j]);
            }
        }
    }
}

std::string max_string(std::string A, int B) {
    std::string answer = "";
    find_max(A, answer, B);
    return answer;
}

int main() {
    std::string A = "254";
    int B = 1;
    std::cout << max_string(A, B);
}