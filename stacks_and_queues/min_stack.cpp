#include <iostream>

struct Node {
     int val;
     Node *next;
     Node(int x) : val(x), next(NULL) {}
};

class MinStack {
    private:
        Node* head;
        Node* min_head;

    public:
        MinStack() {
            head = new Node(0);
            min_head = new Node(0);
        }
        
        void push(int x);

        void pop();

        int top();

        int getMin();

        void print_stack();

        void print_min_stack();
};

void MinStack::print_stack() {
    if (head->next == nullptr) {
        std::cout << "Empty stack!\n";
    }
    else {
        Node* tmp = head->next;
        while (tmp) {
            std::cout << tmp->val << ' ';
            tmp = tmp->next;
        }
        std::cout << '\n';
    }
}

void MinStack::print_min_stack() {
    if (min_head->next == nullptr) {
        std::cout << "Empty min stack!\n";
    }
    else {
        Node* tmp = min_head->next;
        while (tmp) {
            std::cout << tmp->val << ' ';
            tmp = tmp->next;
        }
        std::cout << '\n';
    }
}

void MinStack::push(int x) {
    Node* new_top = new Node(x);
    if (head->next) {
        Node* next = head->next;
        new_top->next = next;
    }
    head->next = new_top;

    if (min_head->next) {
        if (min_head->next->val >= x) {
            Node* new_min = new Node(x);
            new_min->next = min_head->next;
            min_head->next = new_min;
        }
    }
    else {
        Node* new_min = new Node(x);
        min_head->next = new_min;
    }
}

void MinStack::pop() {
    if (head->next) {
        Node* next = head->next;

        if (min_head->next->val == next->val) {
            Node* next_min = min_head->next->next;
            delete min_head->next;
            min_head->next = next_min;
        }

        head->next = next->next;
        delete next;
    }
}

int MinStack::top() {
    if (head->next) {
        return head->next->val;
    }
    return -1;
}

int MinStack::getMin() {
    if (min_head->next) {
        return min_head->next->val;
    }
    return -1;
}



int main() {
    MinStack stack;
    std::cout << "Min: " << stack.getMin() << '\n';
    stack.push(1);
    std::cout << "Min: " << stack.getMin() << '\n';
    stack.push(2);
    std::cout << "Min: " << stack.getMin() << '\n';
    stack.push(0);
    std::cout << "Min: " << stack.getMin() << '\n';
    stack.pop();
    std::cout << "Min: " << stack.getMin() << '\n';
    stack.pop();
    std::cout << "Min: " << stack.getMin() << '\n';
    stack.pop();
    std::cout << "Min: " << stack.getMin() << '\n';
    // stack.pop();
    // stack.print_stack();
}