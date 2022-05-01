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
    ListNode* head = A;
    while (A) {
        if (A->next && A->next->val == A->val) {
            ListNode* tmp = A;
            while (tmp->next && tmp->next->val == tmp->val) {
                tmp = tmp->next;
            }
            A->next = tmp->next;
        }
        A = A->next;
    }
    return head;
}

int main() {
    ListNode* li = create_linked_list({1});
    auto li_ = remove_duplicates(li);
    print_list(li_);
}