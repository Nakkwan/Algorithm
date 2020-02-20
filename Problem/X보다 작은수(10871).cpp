#include <iostream>
using namespace std;

int main() {
	int N, X;
	cin >> N >> X;
	int A = 0;
	for (int i = 0; i < N; i++) {
		cin >> A;
		if (A < X) {
			cout << A << ' ';
		}
	}
	cout << endl;

	return 0;
}