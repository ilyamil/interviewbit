#include <iostream>
#include <stack>
#include <vector>
#include <math.h>

std::vector<int> get_nearest_smaller(std::vector<int> &A) {
    std::vector<int> answer(A.size(), 0);
    std::stack<int> st;
    st.push(-1);
    for (int i = 0; i < A.size(); i++) {
        while (st.top() >= A[i]) {
            st.pop();
        }
        answer[i] = st.top();
        st.push(A[i]);
    }
    return answer;
}

void print_vector(std::vector<int> &A) {
    for (auto el: A) {
        std::cout << el << ' ';
    }
    std::cout << std::endl;
}

int main() {
    // std::vector<int> A = {3, 2, 1};
    // std::vector<int> smaller = get_nearest_smaller(A);

    // std::vector<int> A = {4, 5, 2, 10, 8};
    // std::vector<int> smaller = get_nearest_smaller(A);

    // std::vector<int> A = {4, 4, 2, 10, 8};
    // std::vector<int> smaller = get_nearest_smaller(A);

    // std::vector<int> A = {34, 35, 27, 42, 5, 28, 39, 20, 28};
    // std::vector<int> smaller = get_nearest_smaller(A);

    std::vector<int> A = {39, 27, 11, 4, 24, 32, 32, 1};
    std::vector<int> smaller = get_nearest_smaller(A);
    print_vector(smaller);
}
