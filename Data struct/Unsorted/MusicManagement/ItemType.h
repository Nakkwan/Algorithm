#ifndef ITEMTYPE_H
#define ITEMTYPE_H
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

enum MusicType { UNKNOWN, SONG, MUSICAL, RAP, RNB };

class ItemType {
public:
	ItemType() {
		M_Name = "";
		M_Writer = "";
		M_Singer = "";
		single_label = -1;
		genre = -1;
	}
	~ItemType() {}
	string GetName() const;
	string GetWriter() const;
	string GetSinger() const;
	int GetLabel() const;
	int GetGenre() const;
	void SetName(string inName);
	void SetWriter(string inWriter);
	void SetSinger(string inSinger);
	void SetLabel(int inLabel);
	void SetGenre(int inGenre);
	void SetRecord(string inName, string inWriter, string inSinger, int inLabel, int inGenre);
	void DisplayNameOnScreen();
	void DisplayWriterOnScreen();
	void DisplaySingerOnScreen();
	void DisplayLabelOnScreen();
	void DisplayGenreOnScreen();
	void DisplayRecordOnScreen();
	void SetNameFromKB();
	void SetWriterFromKB();
	void SetSingerFromKB();
	void SetLabelFromKB();
	void SetGenreFromKB();
	void SetRecordFromKB();
	int ReadDataFromFile(std::ifstream& fin);
	int WriteDataToFile(std::ofstream& fout);
	bool operator==(const ItemType& data) {
		if (single_label = data.GetLabel()) {
			return true;
		}
		else {
			return false;
		}
	}

	void operator=(const ItemType& data) {
		M_Name = data.GetName();
		M_Writer = data.GetWriter();
		M_Singer = data.GetSinger();
		single_label = data.GetLabel();
		genre = data.GetGenre();
	}

private:
	string M_Name; 
	string M_Writer;
	string M_Singer;
	int single_label;
	int genre;
};

#endif
