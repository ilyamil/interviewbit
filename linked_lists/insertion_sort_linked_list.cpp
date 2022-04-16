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

ListNode* sort(ListNode* A) {
		if(A == NULL){
			return A;
		}
		
		ListNode* helper = new ListNode(0);
		ListNode* cur = A;
		ListNode* pre = helper;
		ListNode* next = NULL;
		while(cur != NULL){
			next = cur->next;
			while(pre->next != NULL && pre->next->val < cur->val ){
				pre = pre->next;
			}
			cur->next = pre->next;
			pre->next = cur;
			pre = helper;
			cur = next;
		}
		
		return helper->next;
}

int main() {
    auto A = create_linked_list({3, 2, 6});
    auto A_sorted = sort(A);
    while (A_sorted != NULL) {
        std::cout << A_sorted->val << ' ';
        A_sorted = A_sorted->next;
    }
}