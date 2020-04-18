#include "ItemType.h"

int ItemType::O_Total = 0;

string ItemType::GetName() const {
	return O_Name;
}
string ItemType::GetBuyDate() const {
	return O_BuyDate;
}
int ItemType::GetLabel() const {
	return O_Label;
}
int ItemType::GetType() const {
	return O_Type;
}
int ItemType::GetVolume() const {
	return O_Volume;
}
void ItemType::SetName(string inName) {
	O_Name = inName;
}
void ItemType::SetBuyDate(string inDate) {
	O_BuyDate = inDate;
}
void ItemType::SetType(int inType) {
	O_Type = inType;
}
void ItemType::SetLabel(int inLabel) {
	O_Label = inLabel;
}
void ItemType::SetVolume(int inVolume) {
	O_Volume = inVolume;
}

void ItemType::SetRecord(string inName, string inDate, int inType, int inLabel, int inVolume) {
	O_Name = inName;
	O_BuyDate = inDate;
	O_Type = inType;
	O_Label = inLabel;
	O_Volume = inVolume;
}

void ItemType::SetRecordByItem(const ItemType& data) {
	O_Name = data.GetName();
	O_BuyDate = data.GetBuyDate();
	O_Type = data.GetType();
	O_Label = data.GetLabel();
	O_Volume = data.GetVolume();
}

void ItemType::DisplayNameOnScreen() {
	cout << GetName() << endl;
}
void ItemType::DisplayDateOnScreen() {
	cout << GetBuyDate() << endl;
}
void ItemType::DisplayTypeOnScreen() {
	cout << GetType() << endl;
}
void ItemType::DisplayLabelOnScreen() {
	cout << GetLabel() << endl;
}
void ItemType::DisplayVolumeOnScreen() {
	cout << GetVolume() << endl;
}

void ItemType::DisplayRecordOnScreen() {
	cout << "Object name: " << GetName() << endl;
	cout << "Date obtained: " << GetBuyDate() << endl;
	cout << "Type: " << GetType() << endl;
	cout << "Label: " << GetLabel() << endl;
	cout << "Volume: " << GetVolume() << endl;
}

void ItemType::SetNameFromKB() {
	cout << "Object name: ";
	cin >> O_Name;
}

void ItemType::SetDateFromKB() {
	cout << "Date obtained(YYMMDDHH): ";
	cin >> O_BuyDate;
}

void ItemType::SetTypeFromKB() {
	cout << "1.필기류\t2.책\n3.악세러리\t4.화장품\n5.겉옷\t\t6.상의\n7.하의\t\t8.신발\n";
	while (O_Type == -1 || O_Type > 8) {
		cout << "Type: ";
		cin >> O_Type;
		if (O_Type > 8) {
			cout << "Error: Type_out of range\n";
		}
	}
}

void ItemType::SetLabelFromKB() {
	cout << "Label: ";
	cin >> O_Label;
}

void ItemType::SetVolumeFromKB() {
	cout << "Volume: ";
	cin >> O_Volume;
}

void ItemType::SetRecordFromKB() {
	SetNameFromKB();
	SetDateFromKB();
	SetTypeFromKB();
	SetLabelFromKB();
	SetVolumeFromKB();
}

int ItemType::ReadDataFromFile(ifstream& fin) {
	if (fin.is_open()) {
		fin >> O_Name;
		fin >> O_BuyDate;
		fin >> O_Type;
		fin >> O_Label;
		fin >> O_Volume;
		return 1;
	}
	else {
		return 0;
	}
}

int ItemType::WriteDataToFile(ofstream& fout) {
	if (fout.is_open()) {
		fout << O_Name << ' ';
		fout << O_BuyDate << ' ';
		fout << O_Type << ' ';
		fout << O_Label << ' ';
		fout << O_Volume << '\n';
		return 1;
	}
	else {
		return 0;
	}
}

int ItemType::GetTotalObjectNum() {
	return O_Total;
}

RelationType ItemType::CompareByLabel(const ItemType& data) {
	if (this->GetLabel() == data.GetLabel()) {
		return EQUAL;
	}
	else if (this->GetLabel() > data.GetLabel()) {
		return GREATER;
	}
	else {
		return LESS;
	}
}