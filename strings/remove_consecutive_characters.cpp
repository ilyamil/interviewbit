#include <iostream>
#include <string>


std::string remove(std::string A, int B) {
    if (A.length() == 1) {
        if (B == 1) {
            return "";
        }
        return A;
    }

    int slow = 0;
    int fast = 1;
    int cnt = 1;
    char prev = A[slow];
    std::string answer = "";
    while (slow != A.length()) {
        if (A[fast] == prev) {
            cnt++;
        }
        else {
            if (cnt != B) {
                answer.append(A.begin() + slow, A.begin() + slow + cnt);
            }
            slow = fast;
            cnt = 1;
        }
        prev = A[fast++];
    }
    return answer;
}

int main() {
    // std::string A = "aabc";
    // std::string A = "aabbcc";
    std::string A = "abbcc";
    int B = 3;
    std::cout << remove(A, B);
}