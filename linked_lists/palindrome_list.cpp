#include <iostream>
#include <vector>

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

ListNode* create_linked_list(std::vector<int> values) {
    ListNode* running = new ListNode(values[0]);
    ListNode* head = running;
    for (int i = 1; i < values.size(); i++) {
        running->next = new ListNode(values[i]);
        running = running->next;
    }
    return head;
}

void print_list(ListNode* A) {
    ListNode* cur = A;
    while (cur != nullptr) {
        std::cout << cur->val << ' ';
        cur = cur->next;
    }
    std::cout << '\n';
}

ListNode* reverse_list(ListNode* A) {
    ListNode* cur = A;
    ListNode* next = nullptr;
    ListNode* prev = nullptr;
    while (cur != nullptr) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}

bool is_palindrome_list(ListNode* A) {
    ListNode* slow = A;
    ListNode* fast = A;
    while (fast->next != nullptr && fast->next->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode* left_half = A;
    ListNode* right_half = reverse_list(slow->next);

    while (right_half != nullptr) {
        if (left_half->val != right_half->val) {
            return 0;
        }
        left_half = left_half->next;
        right_half = right_half->next;
    }
    
    return 1;
}

int main() {
    ListNode* li = create_linked_list({1, 2, 2});
    auto i = is_palindrome_list(li);
    std::cout << i;
}