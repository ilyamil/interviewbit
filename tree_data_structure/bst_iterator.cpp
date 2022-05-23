#include <iostream>
#include <stack>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
    private:
        std::stack<TreeNode*> st;

    public:
        BSTIterator (TreeNode* root);

        bool hasNext();

        int next();
};

BSTIterator::BSTIterator(TreeNode* root) {
    TreeNode* cur = root;
    while (cur) {
        st.push(cur);
        cur = cur->left;
    }
}

bool BSTIterator::hasNext() {
    return !st.empty();
}

int BSTIterator::next() {
    TreeNode* top = st.top();
    st.pop();
    TreeNode* cur = top->right;
    while (cur) {
        st.push(cur);
        cur = cur->left;
    }
    return top->val;
}

int main() {
    TreeNode* A = new TreeNode(5);
    TreeNode* L = new TreeNode(1);
    TreeNode* R = new TreeNode(6);
    A->left = L;
    A->right = R;

    auto it = BSTIterator(A);
    std::cout << it.next() << ' ';
    std::cout << it.next() << ' ';
    // std::cout << it.next() << ' ';
}