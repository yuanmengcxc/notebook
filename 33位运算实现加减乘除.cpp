#include<iostream>
using namespace std;

const int MIN = INT32_MIN;
//加法
int add(int a, int b) {
	int ans = a;
	while (b != 0) {
		ans = a ^ b;
		b = (a & b) << 1;
		a = ans;
	}
	return ans;
}
//相反数
int neg(int n) {
	return add(~n, 1);
}
//减法
int Minus(int a,int b) {
	return add(a, neg(b));
}

//无讨论除法,a,b都不是整数最小值
int Div(int a, int b) {
	int x = a < 0 ? neg(a) : a;
	int y = b < 0 ? neg(b) : b;
	int ans = 0;
	for (int i = 30; i >= 0; i = Minus(i, 1)) {
		if ((x >> i) >= y) {
			ans |= (1 << i);
			x = Minus(x, y << i);
		}
	}
	return a < 0 ^ b < 0 ? neg(ans) : ans;
}
//除法
int divide(int a, int b) {
	if (a == MIN && b == MIN) {
		// a和b都是整数最小
		return 1;
	}
	if (a != MIN && b != MIN) {
		// a和b都不是整数最小，那么正常去除
		return Div(a, b);
	}
	if (b == MIN) {
		// a不是整数最小，b是整数最小
		return 0;
	}
	// a是整数最小，b是-1，返回整数最大，因为题目里明确这么说了
	if (b == neg(1)) {
		return INT32_MAX;
	}
	// a是整数最小，b不是整数最小，b也不是-1
	a = add(a, b > 0 ? b : neg(b));
	int ans = Div(a, b);
	int offset = b > 0 ? neg(1) : 1;
	return add(ans, offset);
}
//乘法
int multiply(int a, int b) {
	int ans = 0;
	while (b != 0) {
		if ((b & 1)!= 0) {
			ans = add(ans, a);
		}
		a <<= 1;
		b >>= 1;
	}
	return ans;
}
int main() {
	int a = 10;
	int b = 3;
	int result = divide(a, b);
	cout << result << endl;
	return 0;


	return 0;
}
