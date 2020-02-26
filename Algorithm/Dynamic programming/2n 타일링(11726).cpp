#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int tile_num(int N, int* state) {
	if (N == 1) {
		return 1;
	}
	if (N == 2) {
		return 2;
	}

	if (state[N] != 0) {
		return state[N];
	}
	
	/*prevent oversizing*/
	state[N] = tile_num(N - 1, state) % 10007 + tile_num(N - 2, state) % 10007;

	return state[N];
}

int main() {
	int N;
	int num;
	int state[1001] = { 0 };

	cin >> N;

	/*calculate the rest*/
	num = tile_num(N, state) % 10007;
	cout << num << endl;

	return 0;
}

