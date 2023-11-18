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
//先序
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
//中序
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
//后序:两个栈实现
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
//后序：一个栈实现
void posOrderOneStack(TreeNode* h) {
    if (h != nullptr) {
        // 如果始终没有打印过节点，h就一直是头节点
        // 一旦打印过节点，h就变成打印节点
        // 之后h的含义 : 上一次打印的节点
        //头节点一定是最后打印的
        stack<TreeNode*> stack;
        stack.push(h);
        
        while (!stack.empty()) {
            TreeNode* cur = stack.top();
            if (cur->left != nullptr && h != cur->left && h != cur->right) {//h代表截断，即你之后要执行的之前其实已经执行过了
                //有左树且左树未被处理过
                stack.push(cur->left);
            }
            else if (cur->right != nullptr && h != cur->right) {
                // 有右树且右树没处理过
                stack.push(cur->right);
            }
            else {
                // 左树、右树 没有 或者 都处理过了
                cout << cur->val << " ";
                h = stack.top();//h的含义 : 上一次打印的节点
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
    cout << "先序遍历非递归版" << endl;
    inOrder(head);
    cout << "中序遍历非递归版" << endl;
    posOrderTwoStacks(head);
    cout << "后序遍历非递归版 - 2个栈实现" << endl;
    posOrderOneStack(head);
    cout << "后序遍历非递归版 - 1个栈实现" << endl;

    vector<int> preOrderResult = preorderTraversal(head);
    cout << "用一个栈完成先序遍历: ";
    for (int val : preOrderResult) {
        cout << val << " ";
    }
    cout << endl;

    vector<int> inOrderResult = inorderTraversal(head);
    cout << "用一个栈完成中序遍历: ";
    for (int val : inOrderResult) {
        cout << val << " ";
    }
    cout << endl;

    vector<int> posOrderTwoStacksResult = postorderTraversalTwoStacks(head);
    cout << "用两个栈完成后序遍历: ";
    for (int val : posOrderTwoStacksResult) {
        cout << val << " ";
    }
    cout << endl;

    vector<int> posOrderOneStackResult = postorderTraversalOneStack(head);
    cout << "用一个栈完成后序遍历: ";
    for (int val : posOrderOneStackResult) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}