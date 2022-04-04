#include <iostream>
#include <vector>
#include <math.h>
#include <string>

// std::vector<bool> generate_primes(int end) {
//     std::vector<bool> primes(end - 1);
//     for (auto i = 2; i*i <= end; i++) {
//         if (i == 2 || i == 3 || i == 5 || i == 7) {
//             primes[i - 2] = 1;
//         }
//         else if (i % 2 != 0 && i % 3 != 0 && i % 5 != 0 && i % 7 != 0
//                 && std::floor(std::sqrt(i)) != std::sqrt(i)) {
//             primes[i - 2] = 1;
//         }
//     }
//     return primes;
// }

bool is_prime(int n) {
    if(n<=1){
        return false;
    }
    if(n==2 || n == 3){
        return true;
    }

    if(n%2==0 || n%3==0){
      return false;  
    }

    for(int i=5;i*i<=n;i=i+6){
        if(n%i==0 || n%(i+2)==0){
            return false;
        }
    }
    return true;
}

std::vector<int> factorize(int A) {
    for(int i=2; i <= A/2;i++){
        if(is_prime(i) && is_prime(A - i)){
            return {i, A - i};
        }
    }
    return {-1, -1};
}

// std::vector<int> factorize(int A) {
//     auto primes = generate_primes(A);
//     int first = -1;
//     int second = -1;
//     for (int i = 2; i <= A / 2; i++) {
//         if (primes[i - 2] && primes[A - i - 2]) {
//             return {i, A - i};
//             // int min = std::min(i, A - i);
//             // int max = std::max(i, A - i);
//             // if (first == -1 && second == -1 || std::to_string(first) < std::to_string(min)) {
//             //     first = min;
//             //     second = max;
//             // }
//         }
//     }
//     return {first, second};
// }

int main() {
    auto i = factorize(16777214);
    std::cout << i[0] << ' ' << i[1];
    // for (auto i: generate_primes(4)) {
    //     std::cout << i << ' ';
    // }
}