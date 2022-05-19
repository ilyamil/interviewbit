#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<vector<int> > get_anagrams_idx(const vector<string> &A) {
    unordered_map<string, vector<int>> mp;
    for (int i = 0; i < A.size(); i++) {
        string s = A[i];
        sort(s.begin(), s.end());
        mp[s].push_back(i + 1);
    }

    vector<vector<int>> answer;
    for (auto &el: mp) {
        answer.push_back(el.second);
    }
    return answer;
}

int main() {
    vector<string> A = {"cat", "dog", "god", "tca", "tac"};
    auto i = get_anagrams_idx(A);
    for (auto group: i) {
        for (auto el: group) {
            std::cout << el << ' ';
        }
        std::cout << endl;
    }
}