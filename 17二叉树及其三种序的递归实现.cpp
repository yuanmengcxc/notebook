#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};
//����
void preOrder(TreeNode* head) {
    if (head != nullptr) {
        stack<TreeNode*> stack;
        stack.push(head);
        while (!stack.empty()) {
            head = stack.top();
            stack.pop();
            cout << head->val << " ";
            if (head->right != nullptr) {
                stack.push(head->right);
            }
            if (head->left != nullptr) {
                stack.push(head->left);
            }
        }
        cout << endl;
    }
}
//����
void inOrder(TreeNode* head) {
    if (head != nullptr) {
        stack<TreeNode*> stack;
        while (!stack.empty() || head != nullptr) {
            if (head != nullptr) {
                stack.push(head);
                head = head->left;
            }
            else {
                head = stack.top();
                stack.pop();
                cout << head->val << " ";
                head = head->right;
            }
        }
        cout << endl;
    }
}
//����:����ջʵ��
void posOrderTwoStacks(TreeNode* head) {
    if (head != nullptr) {
        stack<TreeNode*> stack,collect;
        
        
        stack.push(head);
        while (!stack.empty()) {
            head = stack.top();
            stack.pop();
            collect.push(head);
            if (head->left != nullptr) {
                stack.push(head->left);
            }
            if (head->right != nullptr) {
                stack.push(head->right);
            }
        }
        while (!collect.empty()) {
            cout << collect.top()->val << " ";
            collect.pop();
        }
        cout << endl;
    }
}
//����һ��ջʵ��
void posOrderOneStack(TreeNode* h) {
    if (h != nullptr) {
        // ���ʼ��û�д�ӡ���ڵ㣬h��һֱ��ͷ�ڵ�
        // һ����ӡ���ڵ㣬h�ͱ�ɴ�ӡ�ڵ�
        // ֮��h�ĺ��� : ��һ�δ�ӡ�Ľڵ�
        //ͷ�ڵ�һ��������ӡ��
        stack<TreeNode*> stack;
        stack.push(h);
        
        while (!stack.empty()) {
            TreeNode* cur = stack.top();
            if (cur->left != nullptr && h != cur->left && h != cur->right) {//h����ضϣ�����֮��Ҫִ�е�֮ǰ��ʵ�Ѿ�ִ�й���
                //������������δ�������
                stack.push(cur->left);
            }
            else if (cur->right != nullptr && h != cur->right) {
                // ������������û�����
                stack.push(cur->right);
            }
            else {
                // ���������� û�� ���� ���������
                cout << cur->val << " ";
                h = stack.top();//h�ĺ��� : ��һ�δ�ӡ�Ľڵ�
                stack.pop();
            }
        }
        cout << endl;
    }
}

vector<int> preorderTraversal(TreeNode* head) {
    vector<int> ans;
    if (head != nullptr) {
        stack<TreeNode*> stack;
        stack.push(head);
        while (!stack.empty()) {
            head = stack.top();
            stack.pop();
            ans.push_back(head->val);
            if (head->right != nullptr) {
                stack.push(head->right);
            }
            if (head->left != nullptr) {
                stack.push(head->left);
            }
        }
    }
    return ans;
}

vector<int> inorderTraversal(TreeNode* head) {
    vector<int> ans;
    if (head != nullptr) {
        stack<TreeNode*> stack;
        while (!stack.empty() || head != nullptr) {
            if (head != nullptr) {
                stack.push(head);
                head = head->left;
            }
            else {
                head = stack.top();
                stack.pop();
                ans.push_back(head->val);
                head = head->right;
            }
        }
    }
    return ans;
}

vector<int> postorderTraversalTwoStacks(TreeNode* head) {
    vector<int> ans;
    if (head != nullptr) {
        stack<TreeNode*> stack, collect;
        stack.push(head);
        while (!stack.empty()) {
            head = stack.top();
            stack.pop();
            collect.push(head);
            if (head->left != nullptr) {
                stack.push(head->left);
            }
            if (head->right != nullptr) {
                stack.push(head->right);
            }
        }
        while (!collect.empty()) {
            ans.push_back(collect.top()->val);
            collect.pop();
        }
    }
    return ans;
}

vector<int> postorderTraversalOneStack(TreeNode* h) {
    vector<int> ans;
    if (h != nullptr) {
        stack<TreeNode*> stack;
        stack.push(h);
        TreeNode* lastPrinted = nullptr;
        while (!stack.empty()) {
            TreeNode* cur = stack.top();
            if ((cur->left != nullptr && lastPrinted != cur->left) || (cur->right != nullptr && lastPrinted != cur->right)) {
                if (cur->left != nullptr && lastPrinted != cur->left) {
                    stack.push(cur->left);
                }
                else if (cur->right != nullptr && lastPrinted != cur->right) {
                    stack.push(cur->right);
                }
            }
            else {
                ans.push_back(cur->val);
                lastPrinted = cur;
                stack.pop();
            }
        }
    }
    return ans;
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
    cout << "��������ǵݹ��" << endl;
    inOrder(head);
    cout << "��������ǵݹ��" << endl;
    posOrderTwoStacks(head);
    cout << "��������ǵݹ�� - 2��ջʵ��" << endl;
    posOrderOneStack(head);
    cout << "��������ǵݹ�� - 1��ջʵ��" << endl;

    vector<int> preOrderResult = preorderTraversal(head);
    cout << "��һ��ջ����������: ";
    for (int val : preOrderResult) {
        cout << val << " ";
    }
    cout << endl;

    vector<int> inOrderResult = inorderTraversal(head);
    cout << "��һ��ջ����������: ";
    for (int val : inOrderResult) {
        cout << val << " ";
    }
    cout << endl;

    vector<int> posOrderTwoStacksResult = postorderTraversalTwoStacks(head);
    cout << "������ջ��ɺ������: ";
    for (int val : posOrderTwoStacksResult) {
        cout << val << " ";
    }
    cout << endl;

    vector<int> posOrderOneStackResult = postorderTraversalOneStack(head);
    cout << "��һ��ջ��ɺ������: ";
    for (int val : posOrderOneStackResult) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}