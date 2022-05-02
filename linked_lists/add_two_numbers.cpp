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

ListNode* push_front(ListNode* source, ListNode* target) {
    target->next = source;
    source = target;
    return source;
}

ListNode* add_two_numbers(ListNode* A, ListNode* B) {
    if (!A) {
        return B;
    }
    if (!B) {
        return A;
    }

    ListNode* head = new ListNode(0);
    ListNode* tail = head;
    int rem = 0;
    int sum = 0;
    while (A || B) {
        sum = rem;
        if (A) {
            sum += A->val;
            A = A->next;
        }
        if (B) {
            sum += B->val;
            B = B->next;            
        }

        rem = sum >= 10? 1: 0;
        sum = sum >= 10? sum % 10: sum;

        tail->next = new ListNode(sum);
        tail = tail->next;
    }

    if (rem) {
        tail->next = new ListNode(rem);
        tail = tail->next;
    }

    return head->next;
}

int main() {
    // 1 -> 2 -> 3 + 4 -> 3 = 5 -> 5 -> 3 => 3 -> 5 -> 5
    // 9 -> 9 + 1 -> 3 = 0 -> 3 -> 1 => 1 -> 3 -> 0
    auto A = create_linked_list({2, 4, 3, 0, 1});
    auto B = create_linked_list({8, 9});
    auto res = add_two_numbers(A, B);
    print_list(res);
}