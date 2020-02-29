#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;



int main() {
	int N;
	int X, Y;
	cin >> N >> X >> Y;
	int size = pow(2, N);

	int** matrix;
	matrix = new int* [size];
	for (int i = 0; i < size; i++) {
		matrix[i] = new int[size];
	}

	matrix[0][0] = 0;

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < pow(2, i - 1); j++) {
			for (int k = 0; k < pow(2, i - 1); k++) {
				int x = j + pow(2, i - 1);
				int y = k + pow(2, i - 1);
				matrix[j][y] = matrix[j][k] + 1 * pow(4, i - 1);
				matrix[x][k] = matrix[j][k] + 2 * pow(4, i - 1);
				matrix[x][y] = matrix[j][k] + 3 * pow(4, i - 1);
			}
		}
	}

	cout << matrix[X][Y] << endl;

	return 0;
}

