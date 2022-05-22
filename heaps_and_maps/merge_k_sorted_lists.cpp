#include <vector>
#include <iostream>
#include <queue>

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
    while (cur) {
        std::cout << cur->val << ' ';
        cur = cur->next;
    }
    std::cout << '\n';
}

struct Compare {
    bool operator()(ListNode* a, ListNode* b) const {
        return a->val > b->val;;
    }
};

ListNode* merge(std::vector<ListNode*> &A) {
    std::priority_queue<ListNode*, std::vector<ListNode*>, Compare> pq;

    for (auto node: A) {
        while (node) {
            pq.push(node);
            node = node->next;
        }
    }

    ListNode* cur = new ListNode(0);
    ListNode* head = cur;
    while(!pq.empty()) {
        cur->next = pq.top();
        cur = cur->next;
        pq.pop();
    }
    cur->next = NULL;

    return head->next;
}

int main() {
    ListNode* A = create_linked_list({1, 10, 20});
    ListNode* B = create_linked_list({4, 11, 13});
    ListNode* C = create_linked_list({3, 8, 9});

    std::vector<ListNode*> input = {A, B, C};
    ListNode* output = merge(input);

    print_list(output);
}