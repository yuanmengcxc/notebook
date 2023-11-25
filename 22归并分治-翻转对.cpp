#include <iostream>
using namespace std;

const int MAXN = 50001;
int help[MAXN];

int merge(int arr[], int l, int m, int r);
int counts(int arr[], int l, int r);
int reversePairs(int arr[], int size);

int reversePairs(int arr[], int size) {
    return counts(arr, 0, size - 1);
}

int counts(int arr[], int l, int r) {
    if (l == r) {
        return 0;
    }
    int m = (l + r) / 2;
    return counts(arr, l, m) + counts(arr, m + 1, r) + merge(arr, l, m, r);
}

int merge(int arr[], int l, int m, int r) {
    int ans = 0;
    for (int i = l, j = m + 1; i <= m; i++) {
        while (j <= r && (long long)arr[i] > (long long)arr[j] * 2) {
            j++;
        }
        ans += j - m - 1;
    }
    int i = l;
    int a = l;
    int b = m + 1;
    while (a <= m && b <= r) {
        help[i++] = arr[a] <= arr[b] ? arr[a++] : arr[b++];
    }
    while (a <= m) {
        help[i++] = arr[a++];
    }
    while (b <= r) {
        help[i++] = arr[b++];
    }
    for (i = l; i <= r; i++) {
        arr[i] = help[i];
    }
    return ans;
}

int main() {
    int arr[] = { 1, 3, 2, 3, 1 };
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << reversePairs(arr, size) << endl;

    return 0;
}