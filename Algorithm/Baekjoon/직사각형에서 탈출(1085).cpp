#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
	int width, height;
	int posX, posY;
	cin >> posX >> posY >> width >> height;

	int xlength, ylength;

	if (posX < width - posX) xlength = posX;
	else xlength = width - posX;

	if (posY < height - posY) ylength = posY;
	else ylength = height - posY;

	if (xlength < ylength) {
		cout << xlength << endl;
	}
	else {
		cout << ylength << endl;
	}

	return 0;
}