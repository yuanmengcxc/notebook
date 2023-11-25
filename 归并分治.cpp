#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 100001;
int arr[MAXN];
int help[MAXN];

long long smallSum(int l, int r);
long long merge(int l, int m, int r);

int main() {
    int a, b, i=0;

    while (cin >> a) { // 注意 while 处理多个 case
        int m = a;
        while (m) {
            cin >> b;
            arr[i++] = b;
            m--;
        }

        long long ans = smallSum(0, a - 1);
        printf("%lld", ans);

    }
}

long long smallSum(int l, int r) {
    if (l == r) {
        return 0;
    }
    int m = (l + r) / 2;
    return smallSum(l, m) + smallSum(m + 1, r) + merge(l, m, r);
}

long long merge(int l, int m, int r) {
    long long ans = 0;
    for (int j = m + 1, i = l, sum = 0; j <= r; j++) {
        while (i <= m && arr[i] <= arr[j]) {
            sum += arr[i++];
        }
        ans += sum;
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