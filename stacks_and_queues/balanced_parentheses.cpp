#include <string>
#include <stack>
#include <iostream>

int is_balanced(std::string A) {
    std::stack<char> parentheses;
    for (auto par: A) {
        if (par == ')' && !parentheses.empty() && parentheses.top() == '(') {
            parentheses.pop();
        }
        else {
            parentheses.push(par);
        }
    }
    return parentheses.empty();
}

int main() {
    std::string A = "()()";
    std::cout << is_balanced(A);
}