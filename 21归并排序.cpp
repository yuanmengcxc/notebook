#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN = 501;

int arr[MAXN];
int help[MAXN];//��������
int n;

// �鲢����ݹ��
void mergeSort1(int l, int r) {
    //�����ٷ�
    if (l == r) {
        return;
    }
    int m = (l + r) / 2;
    //�ݹ�
    mergeSort1(l, m);
    mergeSort1(m + 1, r);
    //
    int i = l, j = m + 1, k = l;//i:ǰ������Ԫ�أ�j:��������Ԫ�� ��k:help�����±�
    while (i <= m && j <= r) {
        help[k++] = arr[i] <= arr[j] ? arr[i++] : arr[j++];
    }//����һ������Խ��
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

// �鲢����ǵݹ��
void mergeSort2() {
    for (int l, m, r, step = 1; step < n; step <<= 1) {//step:����
        l = 0;
        while (l < n) {
            m = l + step - 1;//������һ��Ԫ��λ��
            if (m + 1 >= n) {
                //����Ҳ�û��������
                break;
            }
            r = min(l + (step << 1) - 1, n - 1);//�Ҳ���ұ߽�
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
        // mergeSort1Ϊ�ݹ鷽��
        // mergeSort2Ϊ�ǵݹ鷽��
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