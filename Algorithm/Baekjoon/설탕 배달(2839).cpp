#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
	int kg;
	int count_5;
	int count_3 = -1;
	cin >> kg;
	for (count_5 = kg / 5; count_5 >= 0; count_5--) {
		if ((kg - count_5 * 5) % 3 == 0) {
			count_3 = (kg - count_5 * 5) / 3;
			break;
		}
	}

	if (count_3 == -1) {
		cout << count_3 << endl;
	}
	else {
		cout << count_3 + count_5 << endl;
	}

	return 0;
}