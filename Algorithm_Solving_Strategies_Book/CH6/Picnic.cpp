#include <iostream>
using namespace std;

#define MAX_STUDENT 10

/*
@pre: Set matrix of pair and state of paired student
@post: setting one pair of student and find next pairs
@return: number of pair possibility
*/
int Pair(bool (*pair_matrix)[MAX_STUDENT], bool* pair, int student) {
	int first = -1;
	int count = 0;
	for (int i = 0; i < student; i++) {
		if (pair[i]) {
			first = i;
			break;
		}
	}

	if (first == -1) {
		return 1;
	}
	for (int j = first + 1; j < student; j++) {
		if (pair[j] && pair_matrix[first][j]) {
			pair[j] = pair[first] = 0;
			count += Pair(pair_matrix, pair, student);
			pair[j] = pair[first] = 1;
		}
	}
	return count;
}


int main() {
	int testCase;
	int num_friend;
	int num_student;
	int friend1;
	int friend2;
	cin >> testCase;

	for (int i = 0; i < testCase; i++) {
		bool student[10] = { 0, };
		cin >> num_student;
		for (int i = 0; i < num_student; i++) {
			student[i] = 1;
		}

		cin >> num_friend;
		bool matrix[MAX_STUDENT][MAX_STUDENT] = { 0, };
		for (int j = 0; j < num_friend; j++) {
			cin >> friend1;
			cin >> friend2;
			matrix[friend1][friend2] = 1;
			matrix[friend2][friend1] = 1;
		}
		cout << Pair(matrix, student, num_student) << endl;
	}
}