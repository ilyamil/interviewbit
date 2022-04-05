#include <iostream>
#include <vector>

int remove_duplicates(std::vector<int> &A) {
    if(A.size() == 1) return 1;
    int ptr = 0, i;
    bool flag = true;
    for(i = 0; i < A.size() - 1; i++) {
        if(A[i] != A[i + 1]) {
            A[ptr++] = A[i];
            flag = true;
        }
        else if(A[i] == A[i + 1] && flag) {
            A[ptr++] = A[i];
            flag = false;
        }
    }
    A[ptr++] = A[A.size() - 1];
    return ptr;
}

int main() {
    std::vector<int> A = {1, 1, 1, 2, 3, 3, 3};
}