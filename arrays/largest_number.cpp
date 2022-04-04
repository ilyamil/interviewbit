#include <iostream>
#include <vector>
#include <algorithm>

// struct ModifiedLexComp {
//     bool operator() (const std::string &a, const std::string &b) const {
//         return a + b > b + a
//         //return a + b > b + a? a: b;
//         // auto al = a.length();
//         // auto bl = b.length();
//         // if (al == bl) {
//         //     return a > b;
//         // }
//         // if (a[0] == b[0] && al != bl) {
//         //     return al < bl;
//         // }
//         // return a > b;
//     }
// };

std::string find_largest_num(const std::vector<int> &A) {
    std::vector<std::string> helper(A.size());
    bool all_zeros = true;
    for (auto i = 0; i < A.size(); i++) {
        helper[i] = std::to_string(A[i]);
        if (helper[i] != "0") {
            all_zeros = false;
        }
    }
    if (all_zeros) {
        return "0";
    }

    std::sort(helper.begin(), helper.end(),
              [](const std::string &a, const std::string &b)
              { return a + b > b + a; });

    std::string num = "";
    for (auto i = 0; i < A.size(); i++) {
        num += helper[i];
    }
    return num;
}

int main() {
    //std::vector<int> A = {3, 30, 34, 5, 9};
    //std::vector<int> A = {27, 271};
    //std::vector<int> A = {1, 98, 7, 100, 99};
    std::vector<int> A = {0, 0, 0, 0, 0};
    auto i = find_largest_num(A);
    std::cout << std::endl << i;
}