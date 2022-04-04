#include <iostream>
#include <string>
#include <math.h>

int converter(std::string A) {
    int num = 0;
    for (auto c: A) {
        int part = c - 'A' + 1;
        num = num * 26 + part;
    }
    return num;
}

int main() {
    std::string a = "AAA";
    std::cout << converter(a);
    /// A = 1, Z = 26, AA = 27, AB = 28, AZ = 53
}
