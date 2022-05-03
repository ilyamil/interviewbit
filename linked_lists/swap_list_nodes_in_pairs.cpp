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

ListNode* swap_nodes(ListNode* A) {
    ListNode* prev = new ListNode(0);
    prev->next = A;
    ListNode* cur = A;
    ListNode* head = prev;
    ListNode* next = nullptr;
    ListNode* tmp = nullptr;
    while (cur->next && cur->next->next) {
        next = cur->next->next;
        prev->next = cur->next;
        tmp = cur;
        tmp->next = next;
        prev->next->next = tmp;
        prev = prev->next->next;
        cur->next = next;
        cur = cur->next;
    }
    if (cur->next) {
        prev->next = cur->next;
        cur->next = nullptr;
        prev->next->next = cur;
    }
    return head->next;
}

int main() {
    auto li = create_linked_list({1, 2, 3, 4, 5, 6, 7, 8});
    print_list(swap_nodes(li));
}
