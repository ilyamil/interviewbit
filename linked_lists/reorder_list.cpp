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

ListNode* reverse_list(ListNode* A) {
    ListNode* cur = A;
    ListNode* next = nullptr;
    ListNode* prev = nullptr;
    while (cur != nullptr) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}

ListNode* find_middle_node(ListNode* A) {
    auto slow = A, fast = A;
    while(fast && fast -> next)
        slow = slow -> next,
        fast = fast -> next -> next;
    return slow;    
}

ListNode* reorder_list(ListNode* A) {
    if(A==NULL){
        return NULL;
    }

    ListNode* middle_ptr = find_middle_node(A);

    ListNode* h2=reverse_list(middle_ptr->next);
    middle_ptr->next=NULL;
    ListNode* h1=A;
    while(h1!=NULL && h2!=NULL){
        ListNode* th2= h2->next;
        ListNode* th1= h1->next;
        h1->next=h2;
        h2->next=th1;
        h1=th1;
        h2=th2;
    }
    return A;
}

int main() {
    auto li = create_linked_list({1, 2, 3, 4, 5, 6}); // 1, 6, 2, 5, 4
    auto a = reorder_list(li);
    print_list(a);
}