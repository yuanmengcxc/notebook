#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct ListNode
{
	int val;
	ListNode* next;
};
struct compare
{
	bool operator()(const ListNode* a,const ListNode* b) {
		return a->val > b->val;
	}
};
ListNode* mergeKLists(std::vector<ListNode*>& arr) {
	//                   数据类型        容器类型          比较方式
	std::priority_queue<ListNode*, std::vector<ListNode*>, compare> heap;//建小根堆  优先级队列
	for (ListNode* h : arr) {
		if (h != nullptr) {
			heap.push(h);
		}
	}
	if (heap.empty()) {
		return nullptr;
	}
	ListNode* h = heap.top();
	heap.pop();
	ListNode* pre = h;
	if (pre->next!= nullptr) {
		heap.push(pre->next);
	}
	while (!heap.empty()) {
		ListNode* cur = heap.top();
		heap.pop();
		pre->next= cur;
		pre = cur;
		if (cur->next != nullptr) {
			heap.push(cur->next);
		}
	}
	return h;
}


int main() {
	// 测试样例
	std::vector<ListNode*> arr;
	// 构造测试输入数据
	ListNode* l1 = new ListNode{ 1, nullptr };
	ListNode* l2 = new ListNode{ 4, nullptr };
	ListNode* l3 = new ListNode{ 5, nullptr };
	ListNode* l4 = new ListNode{ 1, nullptr };
	ListNode* l5 = new ListNode{ 3, nullptr };
	ListNode* l6 = new ListNode{ 4, nullptr };
	ListNode* l7 = new ListNode{ 2, nullptr };
	ListNode* l8 = new ListNode{ 6, nullptr };
	l1->next = l2;
	l2->next = l3;
	l4->next = l5;
	l5->next = l6;
	l7->next = l8;
	arr.push_back(l1);
	arr.push_back(l4);
	arr.push_back(l7);

	ListNode* result = mergeKLists(arr);

	// 输出结果
	while (result != nullptr) {
		std::cout << result->val << " ";
		result = result->next;
	}
	std::cout << std::endl;

	// 释放内存
	for (ListNode* node : arr) {
		
			ListNode* temp = node;
			node = node->next;
			delete temp;
	}
	return 0;
}