#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;


int main() {
	int A, B, V;
	cin >> A >> B >> V;
	int count;
	count = (V / (A - B)) - 2;
	int rest;
	rest = V - count * (A - B);
	while (true) {
		if (rest - A <= 0) {
			count++;
			break;
		}
		else {
			count++;
			rest = rest - A;
		}
	}

	cout << count << endl;
	
	return 0;
}