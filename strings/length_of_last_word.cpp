#include <iostream>
#include <string>

int find_length(std::string A) {
    int last_len = 0;
    int cur_len = 0;
    for (int i = 0; i < A.length(); i++) {
        if (A[i] != ' ') {
            cur_len++;
        }
        else if (cur_len > 0) {
            last_len = cur_len;
            cur_len = 0;
        }
    }
    return cur_len > 0? cur_len: last_len;
}

int main() {
    //std::string A = "abc abcad   ";
    // std::string A = "abc";
    std::string A = "   ";
    std::cout << find_length(A);
}