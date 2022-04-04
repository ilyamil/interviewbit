#include <iostream>
#include <vector>
#include <math.h>

int matrix_search(std::vector<std::vector<int> > &A, int B) {
    int low = 0;
    int high = A.size() - 1;
    int mid = (low + high) / 2;
    while (low < high) {
        if (A[mid][A[0].size() - 1] > B) {
            high = mid;
        }
        else if (A[mid][A[0].size() - 1] < B) {
            low = mid + 1;
        }
        else {
            return 1;
        }
        mid = (low + high) / 2;
    }

    int left = 0;
    int right = A[0].size();
    while (left < right) {
        mid = (left + right) / 2;
        if (A[low][mid] == B) {
            return 1;
        }
        if (A[low][mid] > B) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    return A[low][left] == B || A[low][right] == B? 1: 0;
}

// int Solution::searchMatrix(vector<vector > &A, int B) {
//     int start=0,end=A.size()-1,m=A[0].size()-1;
//     while(start<end){
//         int mid=(start+end)/2;
//         if(A[mid][m]==B) {
//             return 1;
//         }
//         else if (A[mid][m]<B) {
//             start=mid+1;
//         }
//         else {
//             end = mid;
//         }
//     }
//     int j=0; // finding the element in the right row
//     for(j=0;j<A[0].size();j++){
//     if(A[start][j]==B){
//     return 1;
//     }
//     }
//     return 0;
// }

int main() {
    std::vector<std::vector<int>> A = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 50}
    };
    // std::vector<std::vector<int>> A = {
    //     {1, 2, 3, 4},
    //     {5, 6, 7, 8},
    //     {9, 10, 11, 12}
    // };
    std::cout << matrix_search(A, 16);
}