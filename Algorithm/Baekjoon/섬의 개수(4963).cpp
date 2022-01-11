#include <iostream>
using namespace std;

#define MAXWIDTH 51
#define MAXHEIGHT 51

int xLoc[] = { -1, 0, 1 };
int yLoc[] = { -1, 0, 1 };

/*
check island and make element 0 for avoid overlap
*/
void check(int(*map)[51], int x, int y) {					
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (x + xLoc[i] >= 0 && y + yLoc[j] >= 0) {
				if (map[x + xLoc[i]][y + yLoc[j]] == 1) {
					map[x + xLoc[i]][y + yLoc[j]] = 0;
					check(map, x + xLoc[i], y + yLoc[j]);
				}
			}
		}
	}
}

/*
count number of island
*/
int island_Num(int (*map)[51], int width, int height) {
	int count = 0;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (map[i][j] == 1) {
				map[i][j] = 0;
				check(map, i, j);
				count++;
			}
		}
	}
	return count;
}


int main() {
	int width, height;
	while (1) {
		int map[MAXHEIGHT][MAXWIDTH] = { 0 };
		
		cin >> width >> height;
		if (width == 0 && height == 0) {
			break;
		}

		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				cin >> map[i][j];
			}
		}

		cout << island_Num(map, width, height) << endl;
	}
	return 0;
}