#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define LOW 100000
#define COL 2

int partition(int** list, int left, int right) { //list1 is list for start_time, list2 is list for finish time
	int pivot, temp;
	int low, high;

	low = left;
	high = right + 1;
	pivot = list[left][1]; // select pivot arbitrary

	/* loop until low and high cross */
	do {
		/* increase low until list2[low] is smaller than pivot */
		do {
			low++; // low는 left+1 에서 시작
		} while (low <= right && list[low][1] < pivot);

		/* decrease low until list2[low] is bigger than pivot */
		do {
			high--;
		} while (high >= left && list[high][1] > pivot);

		// if low is smaller than high, swap value
		if (low < high) {
			swap(list[low], list[high]);
		}
	} while (low < high);

	// if low is bigger than high, swap value pivot and list2[high]. For relocate pivot
	swap(list[left], list[high]);

	// return location of pivot
	return high;
}

void quick_sort(int** list, int left, int right) {

	/* Size of list is bigger than 1 */
	if (left < right) {
		// divide list using partition function
		int pivot = partition(list, left, right);

		// recursion front and back list around the pivot
		quick_sort(list, left, pivot - 1); // front of pivot
		quick_sort(list, pivot + 1, right); // back of pivot
	}
}



int main() {
	int N;				// size of conference
	int start_time = 0, finish_time = 0;
	int count = 1;
	cin >> N;			

	int** list_time;		//Dynamic allocate for conference time
	list_time = new int*[LOW];
	for (int i = 0; i < N; i++) {
		list_time[i] = new int[COL];		//each low of list has two element about start time and finish time
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < COL; j++) {
			cin >> list_time[i][j];
		}
	}

	quick_sort(list_time, 0, N - 1);	//sort the list_time in ascending order by the end if the finish time

	start_time = list_time[0][0];
	finish_time = list_time[0][1];

	for (int i = 1; i < N; i++) {		//Count the number of meeting that has fastest end meeting times without overlapping.
		if (list_time[i][0] >= finish_time) {
			start_time = list_time[i][0];
			finish_time = list_time[i][1];
			count++;
		}
	}

	cout << count << endl;

	for (int i = 0; i < COL; i++) {
		delete[] list_time[i];
	}

	delete[] list_time;

	return 0;
}