#include <iostream>
using namespace std;
#define Maxnum 50


int main() {
	int N, eat = 0, count = 1;
	cin >> N;
	char bomboni[Maxnum][Maxnum];
	char start;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> bomboni[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - 1; j++) {
			swap(bomboni[i][j], bomboni[i][j + 1]);
			for (int m = 0; m < N; m++) {
				start = bomboni[m][0];
				for (int n = 1; n < N; n++) {
					if (start == bomboni[m][n]) {
						count++;
					}
					else {
						start = bomboni[m][n];
						if (count > eat) {
							eat = count;
						}
						count = 1;
						
					}
				}
				if (count > eat) {
					eat = count;
				}
				count = 1;
			}

			for (int n = 0; n < N; n++) {
				start = bomboni[0][n];
				for (int m = 1; m < N; m++) {
					if (start == bomboni[m][n]) {
						count++;
					}
					else {
						start = bomboni[m][n];
						if (count > eat) {
							eat = count;
						}
						count = 1;
						
					}
				}
				if (count > eat) {
					eat = count;
				}
				count = 1;
			}
			swap(bomboni[i][j], bomboni[i][j + 1]);
		}
	}

	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < N; j++) {
			swap(bomboni[i][j], bomboni[i + 1][j]);
			for (int m = 0; m < N; m++) {
				start = bomboni[m][0];
				for (int n = 1; n < N; n++) {
					if (start == bomboni[m][n]) {
						count++;
					}
					else {
						start = bomboni[m][n];
						if (count > eat) {
							eat = count;
						}
						count = 1;
						
					}
				}
				if (count > eat) {
					eat = count;
				}
				count = 1;
			}

			for (int n = 0; n < N; n++) {
				start = bomboni[0][n];
				for (int m = 1; m < N; m++) {
					if (start == bomboni[m][n]) {
						count++;
					}
					else {
						start = bomboni[m][n];
						if (count > eat) {
							eat = count;
						}
						count = 1;
						
					}
				}
				if (count > eat) {
					eat = count;
				}
				count = 1;
			}
			swap(bomboni[i][j], bomboni[i + 1][j]);
		}
	}

	cout << eat << endl;
}