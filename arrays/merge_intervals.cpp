#include <iostream>
#include <vector>


struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

void print_interval(Interval a) {
    std::cout  << '[' << a.start << ", " << a.end << ']';
}

std::vector<Interval> insert(std::vector<Interval> &intervals,
                             Interval newInterval) {
    std::vector<Interval> result;
    int idx = 0;
    while (idx < intervals.size()
           && intervals[idx].end < newInterval.start) {
        result.push_back(intervals[idx]);
        idx++;
    }
    while (idx < intervals.size()
           && intervals[idx].start < newInterval.end) {
        newInterval.start = std::min(intervals[idx].start,
                                     newInterval.start);  
        newInterval.end = std::max(intervals[idx].end,
                                   newInterval.end);  
        idx++;       
    }
    result.push_back(newInterval);
    while (idx < intervals.size()) {
        result.push_back(intervals[idx]);
        idx++;
    }
    return result;
}

int main() {
    // std::vector<Interval> A = {
    //     Interval(1, 2),
    //     Interval(2, 4)
    // };
    // Interval b = Interval(0, 10);

    std::vector<Interval> A = {
        Interval(1, 2),
        Interval(3, 5),
        Interval(6, 7),
        Interval(8, 10),
        Interval(12, 16)
    };
    Interval b = Interval(4, 9);

    // std::vector<Interval> A = {
    //     Interval(1, 3),
    //     Interval(6, 9),        
    // };
    // Interval b = Interval(2, 5);

    // std::vector<Interval> A = {
    //     Interval(1, 2),
    //     Interval(3, 6)
    // };
    // Interval b = Interval(8, 10);

    // std::cout << is_overlapping(Interval(3, 9), Interval(6, 7));
    // std::cout << is_overlapping(Interval(6, 7), Interval(3, 9));
    // std::cout << is_overlapping(Interval(3, 5), Interval(1, 2));
    auto i = insert(A, b);
    for (auto el: i) {
        print_interval(el);
        std:: cout << ' ';
    }
}