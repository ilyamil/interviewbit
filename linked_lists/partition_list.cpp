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

ListNode* partition(ListNode* A, int B) {
    // if (A->next == NULL) {
    //     return A;
    // }

    ListNode* less_ptr = NULL;
    ListNode* greater_ptr = NULL;
    ListNode* less_head = NULL;
    ListNode* greater_head = NULL;
    int i = 0;
    while (A != NULL) {
        auto new_node = new ListNode(A->val);
        if (new_node->val < B) {
            if (less_ptr == NULL) {
                less_ptr = new_node;
                less_head = less_ptr;
            }
            else {
                less_ptr->next = new_node;
                less_ptr = less_ptr->next;
            }
        }
        else {
            if (greater_ptr == NULL) {
                greater_ptr = new_node;
                greater_head = greater_ptr;
            }
            else {
                greater_ptr->next = new_node;
                greater_ptr = greater_ptr->next;
            }
        }
        A = A->next;
        i++;
        if (i == 10) {
            break;
        }
    }

    if (less_head == NULL) {
        return greater_head;
    }

    less_ptr->next = greater_head;
    return less_head;
}

int main() {
    // 1 -> 4 -> 2 -> 3 ==> 1 -> 2 -> 4 -> 3
    auto ll = create_linked_list({1, 4, 3, 2, 5, 2});
    int B = 3;

    // auto ll = create_linked_list({1, 2, 3, 4, 5});
    // int B = 1;

    // auto ll = create_linked_list({1});
    // int B = 1;

    auto ll_p = partition(ll, B);
    while (ll_p != NULL) {
        std::cout << ll_p->val << ' ';
        ll_p = ll_p->next;
    }
}