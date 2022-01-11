#include <iostream>
using namespace std;


int main() {
	int X;
	int stick = 64;
	int count = 1;
	cin >> X;
	
	while (1) {
		if (stick > X) {
			stick /= 2;
		}
		else if(stick == X) {
			break;
		}
		else {
			X = X - stick;
			count++;
		}
	}

	cout << count << endl;
	return 0;
}