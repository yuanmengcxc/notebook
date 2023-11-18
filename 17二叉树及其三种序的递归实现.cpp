#include <iostream>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};
//����
void preOrder(TreeNode* head) {
    if (head == nullptr) {
        return;
    }
    cout << head->val << " ";
    preOrder(head->left);
    preOrder(head->right);
}
//����
void inOrder(TreeNode* head) {
    if (head == nullptr) {
        return;
    }
    inOrder(head->left);
    cout << head->val << " ";
    inOrder(head->right);
}
//����
void posOrder(TreeNode* head) {
    if (head == nullptr) {
        return;
    }
    posOrder(head->left);
    posOrder(head->right);
    cout << head->val << " ";
}

int main() {
    TreeNode* head = new TreeNode(1);
    head->left = new TreeNode(2);
    head->right = new TreeNode(3);
    head->left->left = new TreeNode(4);
    head->left->right = new TreeNode(5);
    head->right->left = new TreeNode(6);
    head->right->right = new TreeNode(7);

    preOrder(head);
    cout << endl << "��������ݹ��" << endl;

    inOrder(head);
    cout << endl << "��������ݹ��" << endl;

    posOrder(head);
    cout << endl << "��������ݹ��" << endl;

    return 0;
}