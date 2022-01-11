#include <iostream>
#include <iomanip>
#include <string>
#define MAX_LENGTH 7
using namespace std;

int main() {
	char key;
	int i = 0;
	int count = 0;
	int num_list[MAX_LENGTH];			//for get number
	int num_count[9] = { 0, };			//for count number
	while (true) {
		key = getchar();	
		if (key == '\n') break;
		num_list[i] = key;
		i++;
		count++;
	}
	/*count each number*/
	for (int j = 0; j < count; j++) {
		char value = num_list[j];
		switch (value)
		{
		case '0':
			num_count[0] += 1;
			break;
		case '1':
			num_count[1] += 1;
			break;
		case '2':
			num_count[2] += 1;
			break;
		case '3':
			num_count[3] += 1;
			break;
		case '4':
			num_count[4] += 1;
			break;
		case '5':
			num_count[5] += 1;
			break;
		case '6':
			num_count[6] += 1;
			break;
		case '7':
			num_count[7] += 1;
			break;
		case '8':
			num_count[8] += 1;
			break;
		case '9':		
			num_count[6] += 1;		//9 equal 6
			break;
		default:
			break;
		}
	}
	
	/*count number of max*/
	int max = 0;
	num_count[6] = (num_count[6] / 2) + (num_count[6] % 2);
	for (int j = 0; j < 9; j++) {
		if (max < num_count[j]) max = num_count[j];
	}
	cout << max << endl;
	
	return 0;
}