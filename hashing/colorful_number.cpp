#include <iostream>
#include <unordered_set>
#include <vector>
#include <string>

int get_subsequence_product(std::string A) {
    int product = 1;
    for (auto el: A) {
        product *= el - '0';
    }
    return product;
}

int check_colorful(int A) {
    std::string str_repr = std::to_string(A);
    std::unordered_set<int> products;
    for (int i = 0; i < str_repr.size(); i++) {
        for (int j = i + 1; j <= str_repr.size(); j++) {
            std::string subsequence = str_repr.substr(i, j - i);
            int product = get_subsequence_product(subsequence);
            if (products.find(product) != products.end()) {
                return 0;
            }
            else {
                products.insert(product);
            }
        }
    }
    return 1;
}

int main() {
    // int A = 3245;
    // std::cout << check_colorful(A);

    int A = 12;
    std::cout << check_colorful(A);
}