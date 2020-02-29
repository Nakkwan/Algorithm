#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

void sort_length(int* list) {
	if (list[0] > list[1]) {
		if (list[1] > list[2]) {
			list[0] = list[2];
			list[1] = list[1];
			list[2] = list[0];
		}
		else {
			if (list[0] > list[2]) {
				list[0] = list[1];
				list[1] = list[2];
				list[2] = list[0];
			}
			else {
				list[0] = list[1];
				list[1] = list[0];
				list[2] = list[2];
			}
		}
	}
	else {
		if (list[0] > list[2]) {
			list[0] = list[2];
			list[1] = list[0];
			list[2] = list[1];
		}
		else {
			if (list[1] > list[2]) {
				list[0] = list[0];
				list[1] = list[2];
				list[2] = list[1];
			}
		}
	}
}

void fill() {

}


int main() {
	int length, width, height;
	int cube_type;
	int sorted_long[3] = { length, width, height };
	cin >> length >> width >> height;
	cin >> cube_type;
	int** cube;

	cube = new int* [cube_type];
	for (int i = 0; i < cube_type; i++) {
		cube[i] = new int[2];
	}

	for (int i = 0; i < cube_type; i++) {
		for (int j = 0; j < 2; j++) {
			cin >> cube[i][j];
		}
	}

	sort_length(sorted_long);

	for (int i = 0; i < cube_type; i++) {
		cube[i][0] = pow(2, cube[i][0]);
	}






	return 0;
}