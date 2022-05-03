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

ListNode* rotate(ListNode* A, int B) {
    if (A && A->next == nullptr) {
        return A;
    }

    ListNode* head = A;
    ListNode* ptr = A;
    int cnt = 1;
    while (ptr->next) {
        ptr = ptr->next;
        cnt++;
    }

    B %= cnt;

    if (B == 0) {
        return A;
    }

    while (cnt != B + 1) {
        A = A->next;
        cnt--;
    }

    ListNode* tail_cur = A->next;
    ListNode* tail_head = tail_cur;
    while (tail_cur->next) {
        tail_cur = tail_cur->next;
    }
    A->next = nullptr;
    tail_cur->next = head;
    return tail_head;
}

int main() {
    // 1, 2, 3, 4, 5
    auto li = create_linked_list({68, 86, 36, 16, 5, 75});
    int B = 90;
    print_list(rotate(li, B));
}