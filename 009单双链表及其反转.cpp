#include<iostream>
using namespace std;

//单链表结构
class ListNode {
public:

	int val;
	ListNode* next;

	ListNode(int v) :val(v), next(nullptr) {};
	ListNode(int v, ListNode* n) :val(v), next(n) {};
};

//双链表结构
class DoubleListNode {
public:
	int val;
	DoubleListNode* next;//指向后继地址
	DoubleListNode* last;//指向前驱地址

	DoubleListNode(int v) :val(v), next(nullptr), last(nullptr) {};
};

//反转单链表
ListNode* reverseList(ListNode* head) {
	ListNode* pre = nullptr;
	ListNode* next = nullptr;
	while (head != nullptr) {
		next = head->next;
		head->next = pre;
		pre = head;
		head = next;
	}
	return pre;
}

DoubleListNode* reverseDoubleList(DoubleListNode* head) {
	DoubleListNode* pre = nullptr;
	DoubleListNode* next = nullptr;
	while (head != nullptr) {
		next = head->next;
		head->next = pre;
		head->last = next;
		pre = head;
		head = next;
	}
	return pre;
}
int main() {
	return 0;
}
