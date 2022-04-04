#include <iostream>
#include <string>
#include <algorithm>

std::string get_next_number(std::string A) {
    int N = A.length();
    
    int pos = N - 1;
    while (pos > 0 && A[pos] <= A[pos - 1]) {
        pos--;
    }

    if (pos == 0) {
        return "-1";
    }

    int just_larger_pos = N - 1;
    while (just_larger_pos > pos - 1 && A[pos - 1] >= A[just_larger_pos]) {
        just_larger_pos--;
    }
    std::swap(A[just_larger_pos], A[pos - 1]);
    std::sort(A.begin() + pos, A.end(), std::less<char>());
    return A;
}

int main() {
    std::string str = "2011";
    std::string ans = "2101";
    std::cout << get_next_number(str);
}