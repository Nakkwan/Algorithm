#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 1000

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
			low++; // low left+1
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
	swap(list[low], list[high]);

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

/*function for set day of hw*/
void set_day(int* list, int date, int score, int& sum) {	//parameter is list of day, day of deadline, score and score sum 
	if (date > 0) {											//for recursion
		if (list[date] == 0) {								//if applied date empty
			list[date] = score;								// set score of that day
			sum += score;
		}
		else {
			set_day(list, date - 1, score, sum);			//if applied day already svheduled, find previous day
		}
	}
}


int main() {
	int N;
	int sum = 0;
	int day[1000] = { 0, };
	cin >> N;
	int** hw_num;
	hw_num = new int* [N];
	for (int i = 0; i < N; i++) {
		hw_num[i] = new int[2];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 2; j++) {
			cin >> hw_num[i][j];
		}
	}
	quick_sort(hw_num, 0, N - 1);

	/*set day of all case*/
	for (int i = N - 1; i >= 0; i--) {
		set_day(day, hw_num[i][0], hw_num[i][1], sum);
	}

	cout << sum << endl;

	for (int i = 0; i < N; i++) {
		delete[] hw_num[i];
	}

	delete[] hw_num;

	return 0;
}