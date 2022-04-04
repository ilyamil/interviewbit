#include <string>
#include <iostream>

int count_min_parentheses(std::string A) {
    int left=0, right=0;
    for(int i = 0; i < A.length(); i++) {
        char curr = A[i];
        if (curr == '(') {
            left++;
        }
        else if(curr == ')') {
            if (left > 0) {
                left--;
            }
            else {
                right++;
            }
        }
    }
    return left+right;
}

int main() {
    // (()))(
    //std::string A = "())";
    // std::string A = "(((";
    // std::string A = "((()((";
    std::string A = ")(";
    std::cout << count_min_parentheses(A);
}