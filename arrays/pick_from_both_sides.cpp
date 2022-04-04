#include <iostream>
#include <vector>

int find_max_sum(std::vector<int>& A, int B) {
    int rolling_sum = 0;
    int N = A.size();
    for (int i = N - B; i < N; i++) {
        rolling_sum += A[i];
    }
    int max_sum = rolling_sum;
    for (int i = 0; i < B; i++) {
        rolling_sum += A[i];
        rolling_sum -= A[N - B + i];
        max_sum = std::max(max_sum, rolling_sum);
    }
    return max_sum;
}

int main() {
    std::vector<int> A = {-969, -948, 350, 150, -59, 724, 966, 430, 107,
    -809, -993, 337, 457, -713, 753, -617, -55, -91, -791, 758, -779,
    -412, -578, -54, 506, 30, -587, 168, -100, -409, -238, 655, 410,
    -641, 624, -463, 548, -517, 595, -959, 602, -650, -709, -164, 374,
    20, -404, -979, 348, 199, 668, -516, -719, -266, -947, 999, -582,
    938, -100, 788, -873, -533, 728, -107, -352, -517, 807, -579, -690,
    -383, -187, 514, -691, 616,
    -65, 451, -400, 249, -481, 556, -202, -697, -776,
    8, 844, -391, -11, -298, 195, -515, 93, -657, -477, 587 };
    int B = 81;
    // std::vector<int> A = {5, 100, 200, 300, -5};
    // int B = 4;
    std::cout << find_max_sum(A, B);
    //std::cout << A.size();
}