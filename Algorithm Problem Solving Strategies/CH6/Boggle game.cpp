#include <iostream>
using namespace std;

/*
Arrays for move location to adjecent element
*/
int locX[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int locY[8] = {-1, -1, -1, 0, 0, 1, 1, 1};

/*
pre: Assign location of start, array board, search word
post: return boolean is word can have found in board
*/
bool hasWord(int x, int y, char (*boggle)[5], string temp) {
	if (x < 0 || x > 5 || y < 0 || y > 5) {		//Location is out of board range
		return false;
	} 
	if (boggle[x][y] != temp[0]) {				//First characteristic of word is not matched with location of board
		return false;
	}
	if (temp.size() == 1) {						//Find word
		return true;
	}
	int nextX;
	int nextY;
	for (int i = 0; i < 8; i++) {				//If first char of word is matched with board, find next char whether it exist in adjacent location
		nextX = x + locX[i];
		nextY = y + locY[i];
		if (hasWord(nextX, nextY, boggle, temp.substr(1))) {
			return true;
		}
	}
	return false;
}

int main() {
	char boggle[5][5];
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> boggle[i][j];
		}
	}
	int x, y;
	string word;
	cin >> word;
	cin >> x >> y;
	bool exist = hasWord(x, y, boggle, word);
	if (exist == true) {
		cout << "Word " << word << " is exist!\n";
	}
	else {
		cout << "Word " << word << " is not exist!\n";
	}


}