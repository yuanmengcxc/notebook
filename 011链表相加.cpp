#include <iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode* next;

    ListNode(int val) : val(val), next(nullptr) {}
};

ListNode* addTwoNumber(ListNode* h1,ListNode* h2) {
    ListNode* ans = nullptr;
    ListNode* cur = nullptr;
    int carry = 0;//½øÎ»
    for (int sum, val; h1 != nullptr || h2 || nullptr; h1 = h1 == nullptr ? nullptr : h1->next, h2 = h2 == nullptr ? nullptr : h2->next) {
        sum = (h1 == nullptr ? 0 : h1->val) + (h2 == nullptr ? 0 : h2->val) + carry;
        val = sum % 10;
        carry = sum / 10;
        if (ans == nullptr) {
            ans = new ListNode(val);
            cur = ans;
        }
        else {
            cur->next = new ListNode(val);
            cur = cur->next;
        }
    }
    if (carry == 1) {
        cur->next = new ListNode(carry);
    }
    return ans;
}

int main() {
    ListNode* h1 = nullptr;
    ListNode* h2 = nullptr;
    ListNode* add;
    h1 = new ListNode(4);
    h1->next = new ListNode(8);
    h1->next->next = new ListNode(9);
    h2 = new ListNode(2);
    h2->next = new ListNode(6);
    h2->next->next = new ListNode(7);
    h2->next->next->next = new ListNode(9);
    add = addTwoNumber(h1, h2);

    while (add != nullptr) {
        if (add->next != nullptr) {
            cout << add->val << "->";
        }
        else {
            cout << add->val << endl;
        }
        add = add->next;
    }

    return 0;
}