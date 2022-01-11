#include <iostream>
#include <map>
#include <string>
using namespace std;


void find_pocket(map<string, int> array, string* poketmon_name, char* find) {
	if (isdigit(find[0])) {
		cout << poketmon_name[atoi(find) - 1] << '\n';
	}
	else {
		cout << array[find] << '\n';
	}
}

int main() {
	cin.tie(NULL);
	ios::ios_base::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;
	int count = 0;

	string input_name;
	char find[21];
	string* poketmon_name;
	poketmon_name = new string[N];

	map<string, int> Pocketmon;

	for (int i = 0; i < N; i++) {
		cin >> input_name;
		Pocketmon[input_name] = i + 1;
		poketmon_name[i] = input_name;
	}

	do {
		cin >> find;

		if (isdigit(find[0])) {
			cout << poketmon_name[atoi(find) - 1] << '\n';
		}
		else {
			cout << Pocketmon[find] << '\n';
		}
		count++;
	} while (count < M);


	return 0;
}


// @Wrong code : Time Over
// @Solution
// 		1. Using map STL
//		2. Do not use unnecessary function
// 		3. cin >> char is more faster than cin >> string
//		4. \n is more faster than endl because of buffer
//		5. cin.tie(NULL) is separate tie of cin, cout. It make code faster but it is not guarantee order of cin, cout
//		6. ios::ios_base::sync_with_stdio(false) make code faster. But this prevents writing code anything related to C.

/*
class Pocketmon {
public:
	int num = 0;
	string name;
};

string find_number(Pocketmon* array, int left, int right, int find) {

	int pivot = (left + right) / 2;

	while (true) {
		if (find < array[pivot].num) {
			return find_number(array, left, pivot, find);
		}
		else if (find > array[pivot].num) {
			return find_number(array, pivot, right, find);
		}
		else {
			return array[pivot].name;
		}
	}
}

string find_pocket(Pocketmon* array, int N, string find) {
	if (isdigit(find.front())) {
		return find_number(array, 0, N, atoi(find.c_str()));
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

	do {
		cin >> find;
		cout << find_pocket(array, N, find) << '\n';
		count++;
	} while (count <= M);


	return 0;
}
*/