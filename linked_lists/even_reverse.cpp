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

ListNode* get_even_nodes(ListNode* A) {
    ListNode* even_tail = new ListNode(0);
    ListNode* even_head = even_tail;
    ListNode* cur = A->next;
    while (cur->next && cur->next->next) {
        even_tail->next = new ListNode(cur->val);
        even_tail = even_tail->next;
        cur = cur->next->next;
    }
    if (cur) {
        even_tail->next = new ListNode(cur->val);
        even_tail = even_tail->next;
    }
    return even_head->next;    
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

ListNode* reverse_even_nodes(ListNode* A) {
    if (A && A->next == nullptr) {
        return A;
    }

    ListNode* even = get_even_nodes(A);
    ListNode* reverse_even = reverse_list(even);
    ListNode* head = A;
    A = A->next;
    while (A->next && A->next->next) {
        A->val = reverse_even->val;
        A = A->next->next;
        reverse_even = reverse_even->next;
    }
    if (reverse_even) {
        A->val = reverse_even->val;
    }
    return head;
}

int main() {
    auto li = create_linked_list({1, 2, 3, 4});
    print_list(reverse_even_nodes(li));
}