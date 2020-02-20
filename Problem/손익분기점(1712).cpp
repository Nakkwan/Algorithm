#include <iostream>

int BreakEvent_Point(int, int, int);

int main() {
	int cost_A, cost_B, cost_C;
	std::cin >> cost_A >> cost_B >> cost_C;
	std::cout << BreakEvent_Point(cost_A, cost_B, cost_C);

	return 0;
}

int BreakEvent_Point(int A, int B, int C) {
	long long count = 1;
	if (B < C) {
		count = A / (C - B) + 1;
		return count;
	}
	else {
		return -1;
	}
}