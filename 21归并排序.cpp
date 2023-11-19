#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN = 501;

int arr[MAXN];
int help[MAXN];//辅助数组
int n;

// 归并排序递归版
void mergeSort1(int l, int r) {
    //不可再分
    if (l == r) {
        return;
    }
    int m = (l + r) / 2;
    //递归
    mergeSort1(l, m);
    mergeSort1(m + 1, r);
    //
    int i = l, j = m + 1, k = l;//i:前数组首元素，j:后数字首元素 ，k:help数组下标
    while (i <= m && j <= r) {
        help[k++] = arr[i] <= arr[j] ? arr[i++] : arr[j++];
    }//必有一个数组越界
    while (i <= m) {
        help[k++] = arr[i++];
    }
    while (j <= r) {
        help[k++] = arr[j++];
    }
    for (k = l; k <= r; k++) {
        arr[k] = help[k];
    }
}

// 归并排序非递归版
void mergeSort2() {
    for (int l, m, r, step = 1; step < n; step <<= 1) {//step:步长
        l = 0;
        while (l < n) {
            m = l + step - 1;//左侧最后一个元素位置
            if (m + 1 >= n) {
                //如果右侧没有数字了
                break;
            }
            r = min(l + (step << 1) - 1, n - 1);//右侧的右边界
            int i = l, j = m + 1, k = l;
            while (i <= m && j <= r) {
                help[k++] = arr[i] <= arr[j] ? arr[i++] : arr[j++];
            }
            while (i <= m) {
                help[k++] = arr[i++];
            }
            while (j <= r) {
                help[k++] = arr[j++];
            }
            for (k = l; k <= r; k++) {
                arr[k] = help[k];
            }
            l = r + 1;
        }
    }
}

int main() {
    while (cin >> n) {
        memset(arr, 0, sizeof(arr));
        memset(help, 0, sizeof(help));
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        // mergeSort1为递归方法
        // mergeSort2为非递归方法
        // mergeSort1(0, n - 1);
        mergeSort2();
        cout << arr[0];
        for (int i = 1; i < n; i++) {
            cout << " " << arr[i];
        }
        cout << endl;
    }
    return 0;
}