#include "ItemType.h"

string ItemType::GetName() const {
	return M_Name;
}
string ItemType::GetWriter() const {
	return M_Writer;
}
string ItemType::GetSinger() const {
	return M_Singer;
}
int ItemType::GetLabel() const {
	return single_label;
}
int ItemType::GetGenre() const {
	return genre;
}
void ItemType::SetName(string inName) {
	M_Name = inName;
}
void ItemType::SetWriter(string inWriter) {
	M_Writer = inWriter;
}
void ItemType::SetSinger(string inSinger) {
	M_Singer = inSinger;
}
void ItemType::SetLabel(int inLabel) {
	single_label = inLabel;
}
void ItemType::SetGenre(int inGenre) {
	genre = inGenre;
}

void ItemType::SetRecord(string inName, string inWriter, string inSinger, int inLabel, int inGenre) {
	M_Name = inName;
	M_Writer = inWriter;
	M_Singer = inSinger;
	single_label = inLabel;
	genre = inGenre;
}

void ItemType::DisplayNameOnScreen() {
	cout << GetName() << endl;
}
void ItemType::DisplayWriterOnScreen() {
	cout << GetWriter() << endl;
}
void ItemType::DisplaySingerOnScreen() {
	cout << GetSinger() << endl;
}
void ItemType::DisplayLabelOnScreen() {
	cout << GetLabel() << endl;
}
void ItemType::DisplayGenreOnScreen() {
	cout << GetGenre() << endl;
}

void ItemType::DisplayRecordOnScreen() {
	cout << "Music name: " << GetName() << endl;
	cout << "Writer: " << GetWriter() << endl;
	cout << "Singer: " << GetSinger() << endl;
	cout << "Label: " << GetLabel() << endl;
	cout << "Genre: " << GetGenre() << endl;
}

void ItemType::SetNameFromKB() {
	cout << "Music name: ";
	cin >> M_Name;
}

void ItemType::SetWriterFromKB() {
	cout << "Writer: ";
	cin >> M_Writer;
}

void ItemType::SetSingerFromKB() {
	cout << "Singer: ";
	cin >> M_Singer;
}

void ItemType::SetLabelFromKB() {
	cout << "Label: ";
	cin >> single_label;
}

void ItemType::SetGenreFromKB() {
	int temp;
	cout << "Genre (0:Unknown, 1:SONG, 2:Musical, 3:Rap, 4:R&B): ";
	cin >> temp;
}

void ItemType::SetRecordFromKB() {
	SetNameFromKB();
	SetWriterFromKB();
	SetSingerFromKB();
	SetLabelFromKB();
	SetGenreFromKB();
}

int ItemType::ReadDataFromFile(ifstream& fin) {
	if (fin.is_open()) {
		fin >> M_Name;
		fin >> M_Writer;
		fin >> M_Singer;
		fin >> single_label;
		fin >> genre;
		return 1;
	}
	else {
		return 0;
	}
}

int ItemType::WriteDataToFile(ofstream& fout) {
	if (fout.is_open()) {
		fout << M_Name << ' ';
		fout << M_Writer << ' ';
		fout << M_Singer << ' ';
		fout << single_label << ' ';
		fout << genre << '\n';
		return 1;
	}
	else {
		return 0;
	}
}