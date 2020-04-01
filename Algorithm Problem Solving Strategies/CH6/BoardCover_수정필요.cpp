#include <iostream>
using namespace std;

#define MAX_WIDTH 21
#define MAX_HEIGHT 21

int firstX[4] = { 1, 1, 0, 0 };
int firstY[4] = { 0, 0, -1, -1 };
int secondX[4] = { 0, 1, 1, -1 };
int secondY[4] = { -1, -1, -1, -1 };

int gameboard(int (*matrix)[MAX_WIDTH], int hei, int wid) {
	int count = 0;
	int locX = -1;
	int locY = -1;
	for (int i = 0; i < hei; i++) {
		for (int j = 0; j < wid; j++) {
			if (matrix[i][j] == 1) {
				locX = i;
				locY = j;
				break;
			}
		}
		if (locY != -1) break;
	}

	if (locX == -1) return 1;

	for (int k = 0; k < 4; k++) {
		int x1 = locX + firstX[k];
		int y1 = locY + firstY[k];
		int x2 = locX + secondX[k];
		int y2 = locY + secondY[k];
		if (x1 >= 0 && x2 >= 0 && y1 >= 0 && y2 >= 0) {
			if (matrix[x1][y1] == 1 && matrix[x2][y2] == 1) {
				matrix[locX][locY] = 0;
				matrix[x1][y1] = 0;
				matrix[x2][y2] = 0;
				count += gameboard(matrix, hei, wid);
				matrix[locX][locY] = 1;
				matrix[x1][y1] = 1;
				matrix[x2][y2] = 1;
			}
		}
	}
	return count;
}

int main() {
	int testCase;
	int height, width;
	cin >> testCase;

	for(int i = 0; i < testCase; i++){
		cin >> height >> width;
		int matrix[MAX_HEIGHT][MAX_WIDTH] = { 0, };
		for (int j = 0; j < height; j++) {
			for (int k = 0; k < width; k++) {
				cin >> matrix[j][k];
			}
		}
		cout << gameboard(matrix, height, width) << endl;;
	}
}