#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int divide_plain(int** matrix, int N, int state, int prio_state, int* coord, int& sum) {
	if (state == 0) {
		int count = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (matrix[i][j] == 1) {
					int x = 0;
					for (int m = 0; m < N; m++) {
						if (matrix[i][m] == 2) {
							x = 1;
							break;
						}
					}
					if (x == 0) {
						divide_plain(matrix, N, 1, 0, coord, sum);
					}
					for (int m = 0; m < N; m++) {
						if (matrix[m][j] == 2) {
							x = 1;
							break;
						}
					}
					if (x == 0) {
						divide_plain(matrix, N, 1, 1, coord, sum);
					}
				}
				else if (matrix[i][j] == 2) {
					count++;
				}
			}
		}
	}
}


int main() {
	int N;
	cin >> N;
	int coordinate[4] = { 0, 0, N, N };
	int** matrix;
	matrix = new int* [N];
	for (int i = 0; i < N; i++) {
		matrix[i] = new int[N];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> matrix[i][j];
		}
	}





	return 0;
}

