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

ListNode* merge(ListNode* A, ListNode* B) {
    ListNode* tail = new ListNode(0);
    ListNode* head = new ListNode(0);
    head->next = tail;
    while (A != nullptr && B != nullptr) {
        if (A->val > B->val) {
            tail->next = new ListNode(B->val);
            B = B->next;
        }
        else {
            tail->next = new ListNode(A->val);
            A = A->next;
        }
        tail = tail->next;
    }

    while (A != nullptr) {
        tail->next = new ListNode(A->val);
        tail = tail->next;
        A = A->next;       
    }
    while (B != nullptr) {
        tail->next = new ListNode(B->val);
        tail = tail->next;
        B = B->next;       
    }

    return head->next->next;
}

int main() {
    auto A = create_linked_list({1, 3, 6});
    auto B = create_linked_list({1});
    print_list(merge(A, B));
}