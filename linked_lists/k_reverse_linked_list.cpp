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

ListNode* reverse_bucket(ListNode* A, int B) {
    ListNode* cur = A;
    ListNode* next = nullptr;
    ListNode* prev = nullptr;
    int cnt = 1;
    while (cnt != B) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
        cnt++;
    }
    return prev;
}

ListNode* reverse_k(ListNode* A, int B) {
    ListNode* tail = new ListNode(0);
    ListNode* head = tail;
    ListNode* current = A;
    while (current) {
        ListNode* cur = current;
        ListNode* next = nullptr;
        ListNode* prev = nullptr;
        int cnt = 1;
        while (cnt <= B) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
            cnt++;
        }
        tail->next = prev;
        while (cnt > 1) {
            tail = tail->next;
            cnt--;
        }
        current = next;
    }
    return head->next;
}

int main() {
    auto li = create_linked_list({1, 2, 3, 4, 5, 6});
    auto li_reversed = reverse_k(li, 1);
    print_list(li_reversed);
}