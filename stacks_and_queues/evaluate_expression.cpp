#include <iostream>
#include <vector>
#include <stack>
#include <string>

int evaluate(std::vector<std::string> &A) {
    std::stack<int> st;
    for (auto el: A) {
        if (el != "+" && el != "-" && el != "*" && el != "/" && el != "") {
            st.push(std::stoi(el));
        }
        else {
            int second = st.top();
            st.pop();
            int first = st.top();
            st.pop();
            if (el == "+") {
                st.push(first + second);
            }
            else if (el == "-") {
                st.push(first - second);
            }
            else if (el == "*" || el == "") {
                st.push(first * second);
            }
            else {
                st.push(first / second);
            }
        }
    }
    return st.top();
}

int main() {
    // std::vector<std::string> A = {"2", "1", "+", "3", ""};
    // std::cout << evaluate(A);

    std::vector<std::string> A = {"4", "13", "5", "/", "+"};
    std::cout << evaluate(A);
}