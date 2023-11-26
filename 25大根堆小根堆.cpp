#include<iostream>
using namespace std;
#include <cstdio>

const int MAXN = 501;

int arr[MAXN];
int n;



//iλ�ã����ϵ��������
void heapInsert(int i) {
	while (arr[i] > arr[(i - 1) / 2]) {
		swap(arr[i], arr[(i - 1) / 2]);
		i = (i - 1) / 2;
	}
}
//iλ�ã����µ��������,size:��ǰ�ѵĴ�С
void heapify(int i, int size) {
	int l = i * 2 + 1;
	while (l < size) {
		int best = arr[l] > arr[l + 1] ? l : l + 1;
		best = arr[i] > arr[best] ? i : best;
		if (best == i)break;
		swap(arr[i], arr[best]);
		i = best;
		l = i * 2 + 1;
	}
}
// �Ӷ����׽�������ѣ�O(n * logn)
// ���ε����������ֵ���ź���O(n * logn)
// ����ʱ�临�Ӷ�O(n * logn)
void heapSort1() {
	for (int i = 0; i < n; i++) {
		heapInsert(i);
	}
	int size = n;
	while (size > 1) {
		swap(arr[0], arr[size - 1]);
		size--;
		heapify(0, size);
	}
}
// �ӵ׵�����������ѣ�O(n)
// ���ε����������ֵ���ź���O(n * logn)
// ����ʱ�临�Ӷ�O(n * logn)
void heapSort2() {
	for (int i = n - 1; i >= 0; i--) {
		heapify(i, n);
	}
	int size = n;
	while (size > 1) {
		swap(arr[0], arr[size - 1]);
		size--;
		heapify(0, size);
	}
}


int main() {
	while (scanf_s("%d", &n) != EOF) {
		for (int i = 0; i < n; i++) {
			scanf_s("%d", &arr[i]);
		}
		// heapSort1Ϊ�Ӷ����׽���Ȼ������
		// heapSort2Ϊ�ӵ׵�������Ȼ������
		// ���ĸ�������
		// heapSort1();
		heapSort2();
		printf("%d", arr[0]);
		for (int i = 1; i < n; i++) {
			printf(" %d", arr[i]);
		}
		printf("\n");
	}

	return 0;
}