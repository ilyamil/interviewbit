#include <string>
#include <iostream>
#include <stack>

int check(std::string A) {
    std::stack<char> st;
    for (auto ch : A) {
        if (ch == ')') {
            auto top = st.top();
            st.pop();

            bool flag = true;
            while (!st.empty() and top != '(') {
                if (top == '+' || top == '-' ||
                    top == '*' || top == '/') {
                        flag = false;
                    }
                top = st.top();
                st.pop();
            }

            if (flag == true)
                return true;
        }
        else {
            st.push(ch);
        }
    }
    return false;
}

int main() {
    std::string A = "((a+b))";
    std::cout << check(A) << '\n';

    std::string B = "(a+(a+b))";
    std::cout << check(B) << '\n';
}