#include <vector>
#include <iostream>
#include <algorithm>

bool check_bookings(std::vector<int> &arrive,
                    std::vector<int> &depart, int K) {
    std::vector<std::pair<int, int>> merged;
    for (int i = 0; i < arrive.size(); i++) {
        merged.push_back(std::make_pair(arrive[i], 1));
        merged.push_back(std::make_pair(depart[i], -1));
    }

    std::sort(merged.begin(), merged.end());

    int counter = 0;
    for (int j = 0; j < merged.size(); j++) {
        counter += merged[j].second;
        if (counter > K) {
            return false;
        }
    }
    return true;
}

int main() {
    std::vector<int> arrive = {1, 2, 3, 4};
    std::vector<int> depart = {10, 2, 6, 14};
    int K = 2;
    auto b = check_bookings(arrive, depart, K);
}