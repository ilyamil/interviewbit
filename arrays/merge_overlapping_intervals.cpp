#include <vector>
#include <iostream>
#include <algorithm>

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

std::vector<Interval> merge(std::vector<Interval> &A) {
    std::sort(A.begin(), A.end(), [](Interval a, Interval b) {
        return a.start < b.start;
    });
    std::vector<Interval> ans = {A[0]};
    for (int i = 1; i < A.size(); i++) {
        if (ans[ans.size() - 1].end >= A[i].start) {
            ans[ans.size() - 1].end = std::max(ans[ans.size() - 1].end,
                                               A[i].end);
        }
        else {
            ans.push_back(A[i]);
        }
    }
    return ans;    
}

int main() {
    std::vector<Interval> A = {
        Interval(1, 3),
        Interval(2, 6),
        Interval(8, 10),
        Interval(15, 18)
    };

    // std::vector<Interval> A = {
    //     Interval(1, 10),
    //     Interval(2, 3),
    //     Interval(6, 13)
    // };

    for (auto el: merge(A)) {
        std::cout << '[' << el.start << ", " << el.end << ']' << ' '; 
    }
}