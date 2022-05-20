#include <iostream>
#include <unordered_map>

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

RandomListNode* copy(RandomListNode* A) {
    std::unordered_map<RandomListNode*, RandomListNode*> mapping;
    RandomListNode* cur = A;
    while (cur) {
        mapping[cur] = new RandomListNode(cur->label);;
        cur = cur->next;
    }

    cur = A;
    while (cur) {
        mapping[cur]->next = mapping[cur->next];
        mapping[cur]->random = mapping[cur->random];
        cur = cur->next;
    }
    return mapping[A];
}

int main() {
    RandomListNode* A = new RandomListNode(1);
    RandomListNode* B = new RandomListNode(2);
    RandomListNode* C = new RandomListNode(3);
    A->next = B;
    B->next = C;
    A->random = C;
    B->random = A;
    C->random = A;

    auto copy_head = copy(A);
    while (copy_head) {
        std::cout << copy_head->label << ' ';
        copy_head = copy_head->next;
    }
}