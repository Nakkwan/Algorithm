#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

void visited(int N, int x, int y, int& sum) {
	/*add weight according to place and index*/
	if (N > 1) {
		int set = pow(2, N - 1);
		if (set > x&& set > y) {							//First quadant
			visited(N - 1, x, y, sum);
		}
		else if (set > x && set <= y) {						//Second quadant
			sum += pow(4, N - 1);

			/*Weight of Nth is already consideration, so reloacte x, y to fit index N - 1*/
			visited(N - 1, x, y - pow(2, N - 1), sum);		
		}
		else if (set <= x && set > y) {						//Third quadant
			sum += 2 * pow(4, N - 1);
			visited(N - 1, x - pow(2, N - 1), y, sum);		
		}
		else {												//Fourth quadant	
			sum += 3 * pow(4, N - 1);
			visited(N - 1, x - pow(2, N - 1), y - pow(2, N - 1), sum);
		}
	}

	/*Add finall weight*/
	else if (N == 1) {						
		if (x == 0 && y == 0) {
			sum += 0;
		} else if (x == 0 && y == 1) {
			sum += 1;
		} else if (x == 1 && y == 0) {
			sum += 2;
		} else if (x == 1 && y == 1) {
			sum += 3;
		}
	}
}



int main() {
	int N;
	int X, Y;
	cin >> N >> X >> Y;

	int sum = 0;
	visited(N, X, Y, sum);

	cout << sum << endl;

	return 0;
}

