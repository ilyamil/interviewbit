#include <iostream>
#include <string>

std::string reverse(std::string A) {
    std::string answer = "";
    int left = -1;
    int right = A.length() - 1;
    int len = 0;
    for (int i = A.length() - 1; i >= 0; i--) {
        if (A[i] != ' ') {
            if (len == 0) {
                right = i;
                left = i;
                len = 1;
            }
            else {
                left--;
                len++;
            }
        }
        else if (A[i] == ' ') {
            if (len > 0) {
                std::string word = std::string(A.begin() + left,
                                               A.begin() + right + 1);
                if (answer.length() == 0) {
                    answer += word;
                }
                else {
                    answer += (" " + word);
                }
                len = 0;
            }
        }
    }

    if (len > 0) {
        if (answer.length() == 0) {
            return std::string(A.begin() + left,
                               A.begin() + right + 1);
        }
        return answer + " " + std::string(A.begin() + left,
                                          A.begin() + right + 1);
    }
    return answer;
}

int main() {
    // "the sky is blue" -> "blue is sky the"
    std::string A = "the sky is blue";
    // std::string A = "this is ib";
    // std::string A = "a";
    // std::string A = " ";
    std::cout << reverse(A);
}