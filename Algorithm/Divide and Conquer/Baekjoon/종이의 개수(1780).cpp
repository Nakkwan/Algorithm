#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

/*Function for check if matrix is consist of only one number*/
int matrix_set(int** matrix, int N) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (matrix[0][0] != matrix[i][j]) {
				 return 1;
			}
		}
	}

	return 0;
}

/*Function for count number of paper that particularly number, and divide matrix*/
void divide_matrix(int** matrix, int* count, int N) {
	int dif;
	dif = matrix_set(matrix, N);

	/*if dif is 0, matrix is consist of only one number*/
	if (dif == 0) {
		if (matrix[0][0] == -1) {
			count[0] += 1;
		}
		else if (matrix[0][0] == 0) {
			count[1] += 1;
		}
		else if (matrix[0][0] == 1) {
			count[2] += 1;
		}
	}

	/*if dif is 1, matrix has many kinds of number*/
	else if (dif == 1) {

		/*allocate matrix*/
		int** sub_mtx;
		sub_mtx = new int* [N / 3];
		for (int i = 0; i < N / 3; i++) {
			sub_mtx[i] = new int[N / 3];
		}

		/*divide matrix by 9, and check each matrix by recursion*/
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				for (int m = (N / 3) * i; m < (N / 3) * (i + 1); m++) {
					for (int n = (N / 3) * j; n < (N / 3) * (j + 1); n++) {
						sub_mtx[m - ((N / 3) * i)][n - ((N / 3) * j)] = matrix[m][n];
					}
				}
				divide_matrix(sub_mtx, count, N / 3);
			}
		}
		for (int i = 0; i < N / 3; i++) {
			delete[] sub_mtx[i];
		}
		delete[] sub_mtx;
	}
}




int main() {
	int N;
	cin >> N;
	int** paper;
	int count[3] = { 0, 0, 0 };			//array for store the paper number
	paper = new int* [N];
	for (int i = 0; i < N; i++) {
		paper[i] = new int[N];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> paper[i][j];
		}
	}

	divide_matrix(paper, count, N);

	cout << count[0] << endl;
	cout << count[1] << endl;
	cout << count[2] << endl;

	for (int i = 0; i < N; i++) {
		delete[] paper[i];
	}
	delete[] paper;


	return 0;
}

