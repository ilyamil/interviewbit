#include <vector>
#include <iostream>
#include <string>

std::vector<std::string> fizzbuzz(int A) {
    std::vector<std::string> answer;
    for (int i = 1; i <= A; i++) {
        if (i % 15 == 0) {
            answer.push_back("FizzBuzz");
        }
        else if (i % 5 == 0) {
            answer.push_back("Buzz");
        }
        else if (i % 3 == 0) {
            answer.push_back("Fizz");
        }
        else {
            answer.push_back(std::to_string(i));
        }
    }
    return answer;
}

int main() {
    auto fb = fizzbuzz(5);
    for (auto el: fb) {
        std::cout << el << ' ';
    }
}