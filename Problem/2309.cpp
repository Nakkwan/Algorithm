#include <iostream>
using namespace std;

int main() {
	int height[9];
	int sum = 0;
	for (int i = 0; i < 9; i++) {
		cin >> height[i];
		sum += height[i];
	}
	for (int i = 0; i < 9; i++) {
		for (int j = i + 1; j < 9; j++) {
			if (sum - (height[i] + height[j]) == 100) {
				height[i] = 0;
				height[j] = 0;
				break;
			}
		}
		if (height[i] == 0) {
			break;
		}
	}
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (height[j] > height[j + 1]) {
				swap(height[j], height[j + 1]);
			}
		}
	}
	for (int i = 0; i < 9; i++) {
		if (height[i] != 0) {
			cout << height[i] << endl;
		}
	}
	
}