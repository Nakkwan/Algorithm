#include <iostream>
#include <algorithm>
#include <map>
#include <string>
using namespace std;

/*For binary Search*/
void Binary_Search(int* array1, int array2, int left, int right) {
	int mid = (left + right) / 2;
	if (left != mid) {
		if (array1[mid] < array2) {
			Binary_Search(array1, array2, mid, right);
		}
		else if (array1[mid] > array2) {
			Binary_Search(array1, array2, left, mid);
		}
		else {
			cout << '1' << ' ';
		}
	}
	else {
		if (array1[mid] == array2) {
			cout << '1' << ' ';
		}
		else if (array1[mid + 1] == array2) {
			cout << '1' << ' ';
		}
		else {
			cout << '0' << ' ';
		}
	}
}


int main() {
	/*To improve time performance*/
	cin.tie();
	ios::ios_base::sync_with_stdio(false);

	int N, M;
	cin >> N;
	int* num_array;
	num_array = new int[N];

	for (int i = 0; i < N; i++) {
		cin >> num_array[i];
	}

	cin >> M;
	int* ident_array;
	ident_array = new int[M];

	for (int i = 0; i < M; i++) {
		cin >> ident_array[i];
	}
	
	/*To make binary search easier*/
	sort(num_array, num_array + N);

	for (int i = 0; i < M; i++) {
		Binary_Search(num_array, ident_array[i], 0, N);
	}

	delete[] num_array;
	delete[] ident_array;

	return 0;
}