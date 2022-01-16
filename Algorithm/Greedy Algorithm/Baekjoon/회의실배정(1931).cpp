#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define LOW 100000
#define COL 2

bool compare(pair<int, int>a, pair<int, int>b) {
	if (a.second == b.second) {
		return a.first < b.first;			//시작과 끝 시간이 같을 때도 고려하여, 시작 시간이 앞선 순으로 배치
	}
	return a.second < b.second;
}


int main() {
	int N;				// size of conference
	int start_time = 0, finish_time = 0;
	int count = 1;
	cin >> N;

	vector<pair <int, int>> list_time(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> list_time[i].first >> list_time[i].second;
	}

	sort(list_time.begin(), list_time.end(), compare);

	start_time = list_time[0].first;
	finish_time = list_time[0].second;

	for (int i = 1; i < N; i++) {		//Count the number of meeting that has fastest end meeting times without overlapping.
		if (list_time[i].first >= finish_time) {
			start_time = list_time[i].first;
			finish_time = list_time[i].second;
			count++;
		}
	}

	cout << count << endl;

	return 0;
}