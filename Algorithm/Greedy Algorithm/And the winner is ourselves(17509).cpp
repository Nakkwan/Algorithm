#include <iostream>
#include <vector>
using namespace std;

int main() {
	int time_solve[11][2];
	int sum = 0;
	int present_time = 0, verdict_panelty = 0, time_panelty = 0;
	for (int i = 0; i < 11; i++) {
		for (int j = 0; j < 2; j++) {
			cin >> time_solve[i][j];
		}
	}
	
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (time_solve[j][0] > time_solve[j + 1][0]) {
				swap(time_solve[j][0], time_solve[j + 1][0]);
			}
		}
	}

	for (int i = 0; i < 11; i++) {
		present_time += time_solve[i][0];
		verdict_panelty += time_solve[i][1] * 20;
		time_panelty += present_time;
	}

	sum = verdict_panelty + time_panelty;

	cout << sum << endl;

	return 0;
}