#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
	int num, temp;
	int new_num;
	int count = 0;
	cin >> num;
	temp = num;
	while (true) {
		new_num = ((temp / 10) + (temp % 10)) % 10 + (temp % 10) * 10;
		if (new_num == num) {
			count++;
			break;
		}
		else {
			count++;
			temp = new_num;
		}
	}
	cout << count << endl;


	return 0;
}