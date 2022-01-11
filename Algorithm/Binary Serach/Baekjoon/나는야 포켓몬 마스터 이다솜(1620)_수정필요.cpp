#include <iostream>
#include <algorithm>
#include <map>
#include <string>
using namespace std;


class Pocketmon {
public:
	int num = 0;
	string name;
};

string find_pocket(Pocketmon* array, int N, string find) {
	if (isdigit(find.front())) {
		for (int i = 0; i < N; i++) {
			if (atoi(find.c_str()) == array[i].num) {
				return array[i].name;
			}
		}
	}
	else {
		for (int i = 0; i < N; i++) {
			if (array[i].name == find) {
				return to_string(array[i].num);
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	ios::ios_base::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;
	int count = 0;

	string find;
	
	Pocketmon* array;
	array = new Pocketmon[N];

	for (int i = 0; i < N; i++) {
		cin >> array[i].name;
	}

	for (int i = 0; i < N; i++) {
		array[i].num = i + 1;
	}

	do{
		cin >> find;
		cout << find_pocket(array, N, find) << endl;
		count++;
	} while (count != M);


	return 0;
}