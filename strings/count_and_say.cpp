#include <vector>
#include <string>
#include <iostream>

std::string count_and_say(int A) {
    if (A == 1) {
        return "1";
    }
    if (A == 2) {
        return "11";
    }

    std::string answer = "11";
    std::string tmp = "";
    int n = 3;
    while (n <= A) {
        int cnt = 1;
        char prev = answer[0];
        for (int i = 1; i < answer.length(); i++) {
            if (answer[i] == prev) {
                cnt++;
            }
            else {
                tmp += (std::to_string(cnt) + prev);
                prev = answer[i];
                cnt = 1;                
            }
        }
        tmp += (std::to_string(cnt) + prev);
        answer = tmp;
        tmp = "";
        n++;
    }
    return answer;
}

int main() {
    int A = 10;
    std::cout << count_and_say(A);
}