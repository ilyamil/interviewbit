#include <iostream>
#include <string>
#include <vector>

int find_longest_sequence_length(std::string A, std::string B) {
    std::vector<std::vector<int>> dp(B.size() + 1);
    dp[0] = std::vector<int>(A.size() + 1);
    for (int row_num = 1; row_num <= B.size(); row_num++) {
        dp[row_num] = std::vector<int>(A.size() + 1);
        for (int col_num = 1; col_num <= A.size(); col_num++) {
            if (B[row_num - 1] == A[col_num - 1]) {
                dp[row_num][col_num] = dp[row_num - 1][col_num - 1] + 1;
            }
            else {
                dp[row_num][col_num] = std::max(dp[row_num - 1][col_num],
                                                dp[row_num][col_num - 1]);
            }
        }
    }
    return dp[dp.size() - 1][dp[0].size() - 1];
}

int main() {
    std::string A = "abbcdgf";
    std::string B = "bbadcgf";

    int length = find_longest_sequence_length(A, B);
    std::cout << length;

}