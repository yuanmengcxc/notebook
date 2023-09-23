#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;


//交换两元素
void swap(int arr[], int i, int j) {
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

////选择排序     时间复杂度：O(N*N)   空间复杂度： O(1)
void selectionSort(int arr[], int length) {
	for (int i = 0; i < length - 1; i++) {
		int min = i;//最小元素的位置
		for (int j = i + 1; j < length; j++) {
			if (arr[min] > arr[j]) {
				min = j;//更新最小元素的位置
			}
		}
		swap(arr, i, min);
	}
}
//冒泡排序     时间复杂度：O(N*N)   空间复杂度： O(1)
void bubbleSort(int arr[], int length) {

	for (int i = 0; i < length - 1; i++) {
		bool flag = false;//记录本趟有没有发生交换
		for (int j = length - 1; j > i; j--) {
			if (arr[j - 1] > arr[j]) {//从后往前，小数往前冒泡
				swap(arr, j - 1, j);
				flag = true;
			}
		}
		if (flag == false) return;//本趟没有发生交换，则直接退出循环
	}
}
//插入排序   时间复杂度：O(N*N)   空间复杂度： O(1)
void insertionSort(int arr[], int length) {
	for (int i = 1; i < length; i++) {
		for (int j = i - 1; j >= 0 && arr[j] > arr[j + 1]; j--) {
			swap(arr, j, j + 1);
		}
	}
}
//随机数组函数
void randomArray(int arr[], int length, int v) {
	srand(time(NULL));//time一直在变，所以rand()生成的数不会是一成不变的（注：只需要调用一次，不要放在for循环里）
	for (int i = 0; i < length; i++) {
		arr[i] = rand() % v + 1;//随机产生：[1,v] 等概率
	}
}
//验证数组元素是否相同
bool sameArray(int arr1[], int arr2[], int length) {
	for (int i = 0; i < length; i++) {
		if (arr1[i] != arr2[i]) {
			return false;
		}
	}
	return true;
}


int main() {
	//随机数组长度
	int N = 1000;
	// 随机数组每个值，在1~V之间等概率随机
	int V = 1000;
	// testTimes : 测试次数
	int testTimes = 10000;
	cout << "测试开始" << endl;
	for (int i = 0; i < testTimes; i++) {
		// 随机得到一个长度，长度在[0~N-1]
		int n = rand() % N;
		// 得到随机数组
		int* arr = new int[n];
		int* arr1 = new int[n];
		int* arr2 = new int[n];
		int* arr3 = new int[n];
		randomArray(arr, n, V);
		for (int j = 0; j < n; j++) {
			arr1[j] = arr[j];
			arr2[j] = arr[j];
			arr3[j] = arr[j];
		}
		selectionSort(arr1, n);
		bubbleSort(arr2, n);
		insertionSort(arr3, n);
		if (!sameArray(arr1, arr2, n) || !sameArray(arr1, arr3, n)) {
			cout << "出错了!" << endl;
			// 当有错了
			// 打印是什么例子，出错的
			// 打印三个功能，各自排序成了什么样
			// 可能要把例子带入，每个方法，去debug！
		}


	}
	cout << "测试结束" << endl;
	return 0;
}
