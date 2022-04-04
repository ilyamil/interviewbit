#include <iostream>
#include <math.h>

int count_min_steps(int A) {
    A = abs(A);
    int sum = 0, step = 0;
    while(sum < A || (sum - A) % 2!= 0){
        step++;
        sum += step;
    }
    return step;
}

int main() {
    auto i = count_min_steps(25);
    std::cout << std::endl << i;
}