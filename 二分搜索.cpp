#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
using namespace std;
//暴力搜索某个值是否存在
bool right(vector<int>& arr, int num) {
	for (int& cur : arr) {
		if (cur == num) {
			return true;
		}
	}
	return false;
}
//二分搜索找某值是否存在
bool exist(vector<int>& arr, int num) {
	if (arr.empty()) {
		return false;
	}
	int l = 0, r = arr.size() - 1, m=0;
	while (l <= r) {
		m = l + (r - l) / 2;
		if (arr[m]==num) {
			return true;
		}
		else if (arr[m] > num) {
			r = m - 1;
		}
		else {
			l = m + 1;
		}
	}
	return false;
}
//随机数组
vector<int> randomArr(int n,int v) {//n:数组长度  v:随机大小
	vector<int> arr(n, 0);
	for (int i = 0; i < n; i++) {
		arr[i] = rand() % v + 1;
	}

	return arr;
}
// 有序数组中找>=num的最左位置(暴力解)
int right1(vector<int>& arr ,int num) {
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] >= num) {
			return i;
		}
	}
	return -1;
}
//有序数组中找>=num的最左位置(二分法)
int findLeft(vector<int>& arr, int num) {
	int l = 0, r = arr.size() - 1, m = 0;
	int ans = -1;
	while (l <= r) {
		m = l + (r - l) / 2;
		if (arr[m] >= num) {
			ans = m;
			r = m - 1;
		}
		else {
			l = m + 1;
		}
	}
	return ans;
}
//有序数组中找<=num的最右位置(暴力解)
int right2(vector<int>& arr, int num) {
	for (int i = arr.size()-1; i >= 0; i--) {
		if (arr[i] <= num) {
			return i;
		}
	}
	return -1;
}
//有序数组中找<=num的最右位置(二分法)
int findRight(vector<int>& arr, int num) {
	int l = 0, r = arr.size() - 1, m = 0;
	int ans = -1;
	while (l <= r) {
		m = l + (r - l)/ 2;
		if (arr[m] <= num) {
			ans = m;
			l = m + 1;
		}
		else {
			r = m - 1;
		}
	}
	return ans;
}
// 峰值元素是指其值严格大于左右相邻值的元素
// 给你一个整数数组 nums，已知任何两个相邻的值都不相等
// 找到峰值元素并返回其索引
// 数组可能包含多个峰值，在这种情况下，返回 任何一个峰值 所在位置即可。
// 你可以假设 nums[-1] = nums[n] = 无穷小
// 你必须实现时间复杂度为 O(log n) 的算法来解决此问题。
int findpeakelement(vector<int>& arr) {
	int n = arr.size();
	if (n == 1) {
		return 0;
	}
	if (arr[0] > arr[1]) {
		return 0;
	}
	if (arr[n - 1] > arr[n - 2]) {
		return n - 1;
	}
	int l = 1, r = n - 2, m = 0, ans = -1;
	while (l <= r) {
		m = l + (r - l) / 2;
		if (arr[m - 1] > arr[m]) {
			r = m - 1;
		}
		else if (arr[m] < arr[m+1]) {
			l= m + 1;
		}
		else {
			ans = m;
			break;
		}
	}
	return ans;
}






int main() {

	int N = 500;//数组长度的范围
	int V = 1000;//随机大小范围
	int testTime = 500000;//测试次数
	cout << "---------------数组中是否存在某值------------------" << endl;
	cout << "测试开始" << endl;
	for (int i = 0; i < testTime; i++) {
		int n = rand() % N;
		vector<int> arr = randomArr(n, V);
		sort(arr.begin(), arr.end());
		int num = rand() % V;
		if (right(arr, num) != exist(arr, num)) {
			cout << "出错了!" << endl;
		}
	}
	cout << "测试结束" << endl;
	cout << "-----------有序数组中找>=num的最左位置--------------" << endl;
	cout << "测试开始" << endl;
	for (int i = 0; i < testTime; i++) {
		int n = rand() % N;
		vector<int> arr = randomArr(n, V);
		sort(arr.begin(), arr.end());
		int num = rand() % V;
		if (right1(arr, num) != findLeft(arr, num)) {
			cout << "出错了!" << endl;
		}
	}
	cout << "测试结束" << endl;
	cout << "-----------有序数组中找<=num的最右位置--------------" << endl;
	cout << "测试开始" << endl;
	for (int i = 0; i < testTime; i++) {
		int n = rand() % N;
		vector<int> arr = randomArr(n, V);
		sort(arr.begin(), arr.end());
		int num = rand() % V;
		if (right2(arr, num) != findRight(arr, num)) {
			cout << "出错了!" << endl;
		}
	}
	cout << "测试结束" << endl;
	cout << "-----------找峰值索引--------------" << endl;
	vector<int> arr = { 1,2,3,4,5,1 };
	int peakindex = findpeakelement(arr);
	cout << "index=" << peakindex << endl;
	return 0;
}