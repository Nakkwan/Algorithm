#include <iostream>
#include <algorithm>
using namespace std;

/*For reverse sort*/
bool type_sort(int i, int j) { return (i > j); }

int Router(int* array, int N, int C, int left, int right) {
	int mid = (left + right) / 2;
	if (mid != left) {
		int count = 1;								//Count the number of router
		int start = 0;								//For differ of location
		for (int i = 1; i < N; i++) {
			if (array[start] - array[i] >= mid) {
				count++;
				start = i;
			}
		}

		if (count >= C) {							//Can increase the length
			return Router(array, N, C, mid, right);
		}
		else {
			return Router(array, N, C, left, mid);
		}
	}
	else {
		return mid;
	}


}

int main() {
	int N, C;
	cin >> N >> C;

	int array[200000] = { 0, };
	
	for (int i = 0; i < N; i++) {
		cin >> array[i];
	}

	/*descending sort about locate*/
	sort(array, array + N, type_sort);

	cout << Router(array, N, C, 1, array[0]);

	return 0;
}