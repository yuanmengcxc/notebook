#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void quickSort1(int arr[], int l, int r);
int partition1(int arr[], int l, int r, int x);
void swap(int arr[], int i, int j);
void quickSort2(int arr[], int l, int r);
void partition2(int arr[], int l, int r, int x);
static int first, last;
//½»»»
void swap(int arr[], int i, int j) {
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

void quickSort1(int arr[], int l, int r) {
    if (l >= r) {
        return;
    }
    int x = arr[l + (rand() % (r - l + 1))];
    int mid = partition1(arr, l, r, x);
    quickSort1(arr, l, mid - 1);
    quickSort1(arr, mid + 1, r);
}

int partition1(int arr[], int l, int r, int x) {
    int a = l, xi = 0;
    for (int i = l; i <= r; i++) {
        if (arr[i] <= x) {
            swap(arr, a, i);
            if (arr[a] == x) {
                xi = a;
            }
            a++;
        }
    }
    swap(arr, xi, a - 1);
    return a - 1;
}


//ÍÆ¼ö
void quickSort2(int arr[], int l, int r) {
    if (l >= r) {
        return;
    }
    int x = arr[l + (rand() % (r - l + 1))];
    partition2(arr, l, r, x);
    int left = first;
    int right = last;
    quickSort2(arr, l, left - 1);
    quickSort2(arr, right + 1, r);
}

void partition2(int arr[], int l, int r, int x) {
    first = l;
    last = r;
    int i = l;
    while (i <= last) {
        if (arr[i] == x) {
            i++;
        }
        else if (arr[i] < x) {
            swap(arr, first++, i++);
        }
        else {
            swap(arr, i, last--);
        }
    }
}

int main() {
    srand(time(0));
    int nums[] = { 4, 3, 2, 1 };
    int n = sizeof(nums) / sizeof(nums[0]);
    quickSort2(nums, 0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}