#include<iostream>
using namespace std;

const int MIN = INT32_MIN;
//�ӷ�
int add(int a, int b) {
	int ans = a;
	while (b != 0) {
		ans = a ^ b;
		b = (a & b) << 1;
		a = ans;
	}
	return ans;
}
//�෴��
int neg(int n) {
	return add(~n, 1);
}
//����
int Minus(int a,int b) {
	return add(a, neg(b));
}

//�����۳���,a,b������������Сֵ
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
//����
int divide(int a, int b) {
	if (a == MIN && b == MIN) {
		// a��b����������С
		return 1;
	}
	if (a != MIN && b != MIN) {
		// a��b������������С����ô����ȥ��
		return Div(a, b);
	}
	if (b == MIN) {
		// a����������С��b��������С
		return 0;
	}
	// a��������С��b��-1���������������Ϊ��Ŀ����ȷ��ô˵��
	if (b == neg(1)) {
		return INT32_MAX;
	}
	// a��������С��b����������С��bҲ����-1
	a = add(a, b > 0 ? b : neg(b));
	int ans = Div(a, b);
	int offset = b > 0 ? neg(1) : 1;
	return add(ans, offset);
}
//�˷�
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
