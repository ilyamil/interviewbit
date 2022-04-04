#include <iostream>
#include <math.h>

int sqrt(int A) {
    if (A == 0) {
        return 0;
    }
    if (A == 1) {
        return 1;
    }

    int lb = 1;
    int ub = A / 2;
    int answer;
    while (lb <= ub) {
        int mid = (lb + ub) / 2;
        int ratio = A / mid;
        if (ratio == mid) {
            return mid;
        }
        if (ratio <= mid) {
            ub = mid - 1;
        }
        else {
            lb = mid + 1;
            answer = mid;
        }
    }
    return answer;
}

int main() {
    // 15 = 3^2 + 6
    // 82 = 3^4 + 1 = 3^2 * 3^2 + 1 = 9^2 + 1
    //std::cout << sqrt(141);
    //std::cout << sqrt(4);
    std::cout << sqrt(930675566);
}