#include<iostream>
#include<vector>
#include<string>
class Bitset {

private:
	std::vector<int> set;
	const int size;
	int zeros;//λͼ���м���0
	int ones;//����1
	bool reverse;//�Ƿ�ת��

public:
	//��ʼ��
	Bitset(int n) :size(n), zeros(n), ones(0), reverse(false){
		set.resize((n + 31) / 32);
	}
	//��i�������1
	void fix(int i) {
		int index = i / 32;
		int  bit = i % 32;
		if (!reverse) {//û��ת��
			if ((set[index] & (1 << bit)) == 0) {
				zeros--;
				ones++;
				set[index] |= (1 << bit);
			}
		}
		else {//��ת��
			if ((set[index] & (1 << bit)) != 0) {
				zeros++;
				ones--;
				set[index] ^= (1 << bit);
			}
		}
	}
	//i������Ƴ�
	void unfix(int i) {
		int index = i / 32;
		int  bit = i % 32;
		if (!reverse) {
			if ((set[index] & (1 << bit)) != 0) {
				ones--;
				zeros++;
				set[index] ^= (1 << bit);
			}
		}
		else {
			if ((set[index] & (1 << bit)) == 0) {
				ones++;
				zeros--;
				set[index] |= (1 << bit);
			}
		}
	}
	//��ת
	void flip() {
		reverse = !reverse;
		int tmp = zeros;
		zeros = ones;
		ones = tmp;
	}
	//�Ƿ�ȫ1
	bool all() {
		return ones == size;
	}
	bool one() {
		return ones > 0;
	}
	//1������
	int count() {
		return ones;
	}
	std::string toString() {
		std::string str;
		str.reserve(size);
		for (int i = 0, k = 0, number, status; i < size; k++) {
			number = set[k];
			for (int j = 0; j < 32 && i < size; j++, i++) {
				status = (number >> j) & 1;
				status ^= reverse ? 1 : 0;
				str.push_back('0' + status);
			}
		}
		return str;
	}


};

int main() {



	return 0;
}