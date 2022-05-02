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

ListNode* remove_nth_node(ListNode* A, int B) {
    ListNode* len_ptr = A;
    int len = 0;
    while (len_ptr) {
        len_ptr = len_ptr->next;
        len++;
    }
    if (B >= len) {
        return A->next;
    }

    ListNode* head = A;
    int cur_len = 0;
    while (cur_len != len - B - 1) {
        cur_len++;
        A = A->next;
    }
    A->next = A->next->next;
    return head;
}

int main() {
    ListNode* A = create_linked_list({1, 2, 3, 4, 5});
    ListNode* A_ = remove_nth_node(A, 5);
    print_list(A_);
}