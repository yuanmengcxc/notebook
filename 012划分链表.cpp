#include <iostream>
using namespace std;



struct ListNode {
    int val;
    ListNode* next;

    ListNode(int val) : val(val), next(nullptr) {}
    ListNode(int val, ListNode* next) : val(val), next(next) {}
};

ListNode* partition(ListNode* head, int x) {
    ListNode* leftHead = nullptr;//小头
    ListNode* leftTail = nullptr; //小尾
    ListNode* rightHead = nullptr;//大头
    ListNode* rightTail = nullptr; //大尾
    ListNode* next = nullptr;

    while (head != nullptr) {
        next = head->next;
        head->next = nullptr;
        if (head->val < x) {
            if (leftHead == nullptr) {
                leftHead = head;
            }
            else {
                leftTail->next = head;
            }
            leftTail = head;
        }
        else {
            if (rightHead == nullptr) {
                rightHead = head;
            }
            else {
                rightTail->next = head;
            }
            rightTail = head;
        }
        head = next;
    }
    if (leftHead == nullptr) {
        return rightHead;
    }
    leftTail->next = rightHead;

    return leftHead;
}

int main() {
    ListNode* head = nullptr;
    head = new ListNode(6);
    head->next = new ListNode(5);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(2);
    head->next->next->next->next->next = new ListNode(1);
    head->next->next->next->next->next->next = new ListNode(7);
    ListNode* cur = partition(head,4);
    while (cur != nullptr) {
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;
    return 0;
}