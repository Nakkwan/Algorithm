#include <iostream>
using namespace std;

int main() {
	int L, P, V;
	int count = 1;
	int day = 0;
	do {
		cin >> L >> P >> V;
		if (L != 0) {
			if ((V % P) > L) {
				day = L + (V / P) * L;
			}
			else {
				day = (V % P) + (V / P) * L;
			}
			cout << "Case " << count << ": " << day << endl;
			count++;
		}
	} while (L != 0);

	return 0;
}