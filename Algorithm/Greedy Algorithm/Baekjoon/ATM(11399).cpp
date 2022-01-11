#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	int people_num;
	int temp;
	int sum = 0;
	int count = 0;
	vector<int> time;
	cin >> people_num;

	for (int i = 0; i < people_num; i++) {		//get time
		cin >> temp;
		time.push_back(temp);
	}

	sort(time.begin(), time.end());				//Sort ascending order, because first withdrawer's time is most overlapped

	for (int i = people_num; i > 0; i--) {
		sum += time[count] * i;
		count++;
	}

	cout << sum << endl;

	return 0;
}