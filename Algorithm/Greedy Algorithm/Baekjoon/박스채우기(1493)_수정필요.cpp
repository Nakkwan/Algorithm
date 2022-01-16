#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

bool type_sort(int* i, int* j) { return (i[0] > j[0]); }

int fill(int** cube, int N, int total_volume) {
	int Rest_volume = total_volume;
	int used_cube = 0;

	for(int i = 0; i < N; i++){
		int cube_volume = pow(2, cube[i][0]);
		for(int j = 0; j < cube[i][1]; j++){
			if(Rest_volume - cube_volume > 0){
				Rest_volume = Rest_volume - cube_volume;
				used_cube++;
			}
			else{
				break;
			}
		}
	}

	if(Rest_volume == 0){
		return used_cube;
	}
	else{
		return -1;
	}
}

int main() {
	int length, width, height;
	int cube_type;
	int sorted_long[3] = { length, width, height };
	cin >> length >> width >> height;
	cin >> cube_type;
	int** cube;

	cube = new int* [cube_type];
	for (int i = 0; i < cube_type; i++) {
		cube[i] = new int[2];
	}

	for (int i = 0; i < cube_type; i++) {
		for (int j = 0; j < 2; j++) {
			cin >> cube[i][j];
		}
	}

	int total_volume = length * width * height;

	sort(cube, cube + cube_type, type_sort);

	cout << fill(cube, N, total_volume) << '\n';

	return 0;
}