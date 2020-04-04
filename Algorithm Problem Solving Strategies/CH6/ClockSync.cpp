#include <iostream>
#include <cmath>
#include <algorithm>
#define BIG 50000000
using namespace std;

//����ġ���� ���ư��� �ð� ��ȣ
int matrix[10][6] = { {0, 1, 2, -1, -1, -1}, {3, 7, 9, 11, -1, -1}, {4, 10, 14, 15, -1, -1}, {0, 4, 5, 6, 7, -1}, {6, 7, 8, 10, 12, -1},
{0, 2, 14, 15, -1, -1}, {3, 14, 15, -1, -1, -1}, {4, 5, 7, 14, 15, -1}, {1, 2, 3, 4, 5, -1}, {3, 4, 5, 9, 13, -1} };

//�ð谡 �� 12������ Ȯ��
int check12(int clock[16]) {
	for (int i = 0; i < 16; i++) {
		if (clock[i] != 12) {
			return 0;
		}
	}

	return 1;
}

//�ش� ����ġ�� ������ �ð� ���� ����
void ClickSwitch(int clock[16], int swit) {
	for (int i = 0; i < 6; i++) {
		if (matrix[swit][i] != -1) {
			clock[matrix[swit][i]] += 3;
			if (clock[matrix[swit][i]] == 15) {
				clock[matrix[swit][i]] = 3;
			}
		}
		else {
			break;
		}
	}
}


int LeastRatate(int clock[16], int swit) {
	int count = BIG;
	if (swit == 10) {					//����ġ�� 10������ �� ���������� 12�ð� �ȵ����� ū �� ����
		if (!check12(clock)) return BIG;
		else return 0;
	}
	if (!check12(clock)) {
		for (int i = 0; i < 4; i++) {	//0������ 3�� ������
			count = min(count, i + LeastRatate(clock, swit + 1));	//���� ����ġ ������ + ���� Ƚ�� �� ���� �� ����
			ClickSwitch(clock, swit);								//����ġ ������
		}

	}
	else {
		return 0;
	}

	return count;
}

int main() {
	int testCase;
	int count;

	cin >> testCase;

	for (int i = 0; i < testCase; i++) {
		int clock[16];
		for (int j = 0; j < 16; j++) {
			cin >> clock[j];
		}
		count = LeastRatate(clock, 0);
		if (count == BIG) {
			cout << "-1\n";
		}
		else {
			cout << count << endl;
		}
	}
}