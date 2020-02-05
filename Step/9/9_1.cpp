#include <iostream>

int BreakEvent_Point(int, int, int);

int main() {
	int cost_A, cost_B, cost_C;
	do {
		std::cin >> cost_A >> cost_B >> cost_C;
		if (0 < cost_A < 2100000000 && 0 < cost_B < 2100000000 && 0 < cost_C < 2100000000) {
			break;
		}
	} while (true);
	std::cout << BreakEvent_Point(cost_A, cost_B, cost_C);

	return 0;
}

int BreakEvent_Point(int A, int B, int C) {
	int count = 1;
	if (B < C) {
		while (true) {
			if (A + B * count < C * count) {
				return count;
			}
			else {
				count++;
			}
		}
	}
	else {
		return -1;
	}
}