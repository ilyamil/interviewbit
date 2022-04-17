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

int get_kth_node(ListNode* A, int B) {
    int N = 0;
    ListNode* cur = A;
    while (cur != nullptr) {
        cur = cur->next;
        N++;
    }

    int cnt = 0;
    while (A != nullptr) {
        if (++cnt == (N/2 + 1 - B)) {
            return A->val;
        }
        A = A->next;
    }
    return -1;
}

int main() {
    // 3 -> 4 -> 7 -> 5 -> 6 -> 16 -> 15 -> 61 -> 16
    // 3 -> 4 -> 7
    // auto ll = create_linked_list({3, 4, 7, 5, 6, 16, 15, 61, 16});
    // int B = 3;

    auto ll = create_linked_list({1, 14, 6, 16, 4, 10});
    int B = 3;

    std::cout << get_kth_node(ll, B);
}