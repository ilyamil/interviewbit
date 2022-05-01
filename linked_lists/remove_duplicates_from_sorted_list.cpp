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


ListNode* remove_duplicates(ListNode* A) {
    ListNode* sentinel = new ListNode(-1);
    sentinel->next = A;
    ListNode* pred = sentinel;
    
    while (A) {
        if (A->next && A->next->val == A->val) {
            while (A->next && A->next->val == A->val) {
                A = A->next;
            }
            pred->next = A->next;
        }
        else {
            pred = pred->next;
        }
        A = A->next;
    }
    
    return sentinel->next;
}

int main() {
    ListNode* li = create_linked_list({1, 1, 2, 2, 3, 4, 5});
    auto li_ = remove_duplicates(li);
    print_list(li_);
}