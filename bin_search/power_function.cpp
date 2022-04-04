#include <iostream>
#include <math.h>

int pow(int x, int n, int d) {
    if (d == 1) {
        return 0;
    }
    if (x == 0) {
        return 0;
    }

    long long int ans = 1, y = x % d;
    
    while (n > 0) {
        if (n % 2 == 1) {
            ans = (ans * y) % d;
        }
        y = (y*y) % d;
        n--;
    }
    return ans < 0? (d - abs(ans) % d): ans;  
}

int main() {
    // 16 = 2 * 2 * 2 * 2 = 4 * 4
    // 64 = 2 * 2 * 2 * 2 * 2 * 2 = 4 * 4 * 4 = 8 * 8 = 2^6 = 2^3 * 2^3
    // 1024 = 2^10 = 2^5 * 2^5 = 2*(2^2 * 2^2) * 2^5
    // 4096 = 2^12 = 2*6 * 2^6 = 2^3 * 2^3 * 2^6 = 
    // 2^32 = 2^16 * 2^16 = 2^8 * 2^8 * 2^16 = 2^4 * 2^4 * 2^8 ^ 2^16
    // std::cout << std::sqrt(36);
    // int x = 3;
    // int n = 16;
    // int d = 5;

    // int x = 3;
    // int n = 16;
    // int d = 1;

    int x = 3;
    int n = 7;
    int d = 1;

    //std::cout << pow(x, n, d) << ' ' << int(std::pow(x, n)) % d;
    int k = 9;
    std::cout << (k&1);
}