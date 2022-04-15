#include <iostream>
#include <vector>

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

ListNode* sort_list(ListNode* A) {
    ListNode* slow = A;
    ListNode* fast = A;
    while (fast != NULL) {
        if(fast->val != 1){
            std::swap(fast->val , slow->val);
            slow = slow->next;
        }
        fast = fast->next;
    }
    return A;
}

ListNode* create_linked_list(std::vector<int> values) {
    ListNode* running = new ListNode(values[0]);
    ListNode* head = running;
    for (int i = 1; i < values.size(); i++) {
        running->next = new ListNode(values[i]);
        running = running->next;
    }
    return head;
}

int main() {
    // auto head = create_linked_list({1, 0, 1, 0, 0});
    // auto head = create_linked_list({1, 1, 1, 1, 1});
    // auto head = create_linked_list({1, 1, 1, 1, 0});
    // auto head = create_linked_list({1, 0, 0, 0, 0});
    // auto head = create_linked_list({0, 1, 0, 0, 1, 1, 1, 1, 0, 1, 0, 0, 1});
    // auto head = create_linked_list({1});
    auto head = create_linked_list({0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1});
    auto sorted_head = sort_list(head);
    while (sorted_head != NULL) {
        std::cout << sorted_head->val << ' ';
        sorted_head = sorted_head->next;
    }
}