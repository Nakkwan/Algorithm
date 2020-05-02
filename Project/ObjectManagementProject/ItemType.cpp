#include "pch.h"
#include "ItemType.h"

SingleLinkedList<string> ItemType::O_TypeList;

string ItemType::GetName() const {
	return O_Name;
}
int ItemType::GetBuyDate() const {
	return O_BuyDate;
}
int ItemType::GetLabel() const {
	return O_Label;
}
string ItemType::GetType() const {
	return O_Type;
}
int ItemType::GetVolume() const {
	return O_Volume;
}
int ItemType::GetRoomID() const {
	return O_RoomID;
}
int ItemType::GetDrawerID() const {
	return O_DrawerID;
}
int ItemType::GetContainerID() const {
	return O_ContainerID;
}
string ItemType::GetPicture() const {
	return O_Picture;
}
void ItemType::SetName(string inName) {
	O_Name = inName;
}
void ItemType::SetBuyDate(int inDate) {
	O_BuyDate = inDate;
}
void ItemType::SetType(string inType) {
	O_Type = inType;
}
void ItemType::SetLabel(int inLabel) {
	O_Label = inLabel;
}
void ItemType::SetVolume(int inVolume) {
	O_Volume = inVolume;
}
void ItemType::SetPicture(string inPic) {
	O_Picture = inPic;
}

void ItemType::SetContainerID() {
	O_ContainerID = (O_Label % 10000) / 100;
}
void ItemType::SetDrawerID() {
	O_DrawerID = (O_Label % 1000000) / 10000;
}
void ItemType::SetRoomID() {
	O_RoomID = O_Label / 1000000;
}

void ItemType::SetRecord(string inName, int inDate, string inType, int inLabel, int inVolume) {
	O_Name = inName;
	O_BuyDate = inDate;
	O_Type = inType;
	O_Label = inLabel;
	O_Volume = inVolume;
	SetContainerID();
	SetDrawerID();
	SetRoomID();
}

void ItemType::SetRecordByItem(const ItemType& data) {
	O_Name = data.GetName();
	O_BuyDate = data.GetBuyDate();
	O_Type = data.GetType();
	O_Label = data.GetLabel();
	O_Volume = data.GetVolume();
	O_ContainerID = data.GetContainerID();
	O_DrawerID = data.GetDrawerID();
	O_RoomID = data.GetRoomID();
}	

void ItemType::DisplayNameOnScreen() {
	cout << "Object name: " << GetName() << endl;
}
void ItemType::DisplayDateOnScreen() {
	cout << "Date obtained: " << GetBuyDate() << endl;
}
void ItemType::DisplayTypeOnScreen() {
	cout << "Type: " << GetType() << endl;
}
void ItemType::DisplayLabelOnScreen() {
	cout << "Label: " << GetLabel() << endl;
}
void ItemType::DisplayVolumeOnScreen() {
	cout << "Volume: " << GetVolume() << endl;
}
void ItemType::DisplayContainerIDOnScreen() {
	cout << "ContainerID: " << GetContainerID() << endl;
}
void ItemType::DisplayDrawerIDOnScreen() {
	cout << "DrawerID: " << GetDrawerID() << endl;
}
void ItemType::DisplayRoomIDOnScreen() {
	cout << "RoomID: " << GetRoomID() << endl;
}
void ItemType::DisplayPictureOnScreen() {
	cout << "Object Picture: " << GetPicture() << endl;
}
void ItemType::DisplayRecordOnScreen() {
	cout << "Object name: " << GetName() << endl;
	cout << "RoomID: " << GetRoomID() << endl;
	cout << "DrawerID: " << GetDrawerID() << endl;
	cout << "ContainerID: " << GetContainerID() << endl;
	cout << "Label: " << GetLabel() << endl;
	cout << "Type: " << GetType() << endl;
	cout << "Date obtained: " << GetBuyDate() << endl;
	cout << "Volume: " << GetVolume() << endl;
	cout << "Object Picture: " << GetPicture() << endl;
}

void ItemType::SetNameFromKB() {
	cout << "Object name: ";
	cin >> O_Name;
}

void ItemType::SetDateFromKB() {
	int year, month, day;
	do {
		cout << "Date obtained(YYYYMMDD): ";
		cin >> O_BuyDate;
		year = O_BuyDate / 10000;
		month = (O_BuyDate % 10000) / 100;
		day = O_BuyDate % 100;
		if (CheckDate(year, month, day)) {
			break;
		}
		else {
			cout << "Error: Invalid Date\n";
		}
	} while (1);
}

bool ItemType::CheckDate(int year, int month, int day) {
	if ((month % 2 == 1)) //odd month   
	{
		if (month <= 7)
			if (day <= 0 || day > 31) return false;
			else // month > 7   
				if (day <= 0 || day > 30) return false;
	}
	else //even month  
	{
		if (month <= 6) {
			if (month == 2)
			{
				if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)) // leap year  
				{
					if (day <= 0 || day > 30) return false;
				}
				else if (day <= 0 || day > 28) return false;

			}
			if (day <= 0 || day > 30) return false;
		}
		else { // month > 6  

			if (day <= 0 || day > 31) return false;
		}
	}
	return true;
}

void ItemType::DisplayTypeList() {
	if (O_TypeList.IsEmpty()) {
		cout << "ex) stationery, accessary, cosmetics, clothes, tool, etc\n";
	}
	else {
		cout << "\t<Current Type List>\n";
		string temp;
		int  count = 1;
		int pointer = O_TypeList.GetNextItem(temp);
		while (pointer != -1) {
			cout << count << '.';
			cout << temp << "  ";
			if (count > 5) {
				cout << '\n';
			}
		}
		cout << "\n";
	}
}

void ItemType::SetTypeFromKB() {
	DisplayTypeList();
	cout << "Type: ";
	cin >> O_Type;
	string temp;
	if (!O_TypeList.Get(temp)) {
		O_TypeList.Add(temp);
	}
}

void ItemType::SetLabelFromKB() {
	int r, dr, con, la;
	do {
		cout << "(R: RoomID, SS: StorageID, CC: ContainerID, LL: Unique Label(10~99))\n";
		cout << "Label(RSSCCLL): ";
		cin >> O_Label;
		if (O_Label > 9999999 || O_Label < 1000000) {
			cout << "Error: Label_out of range\n\n";
			continue;
		}
		r = O_Label / 1000000;
		dr = O_Label / 10000;
		con = O_Label / 100;
		la = O_Label % 100;
		if (la > 9) {
			if (r == O_RoomID) {
				if (dr == O_DrawerID) {
					if (con == O_ContainerID) {
						break;
					}
					else {
						cout << "Error: Label_Check ContainerID\n\n";
					}
				}
				else {
					cout << "Error: Label_Check DrawerID\n\n";
				}
			}
			else {
				cout << "Error: Label_Check RoomID\n\n";
			}
		}
		else {
			cout << "Error: Out_of_range\n\n";
		}
	} while (true);
}

void ItemType::SetTempLabelFromKB() {
	 do {
		cout << "Label(10~999): ";
		cin >> O_Label;
		if (O_Label > 999 || O_Label < 10) {
			cout << "Error: Label_out of range\n\n";
		}
	 } while (O_Label > 999 || O_Label < 10);
}

void ItemType::SetVolumeFromKB() {
	cout << "Volume: ";
	cin >> O_Volume;
}

void ItemType::SetContainerIDFromKB() {
	int r, dr, con;
	do {
		cout << "(R: RoomID(1~9), DD: DrawerID(10~99), CC: ContainerID(10~99))\n";
		cout << "ContainerID(RDDCC): ";
		cin >> O_ContainerID;
		if (O_ContainerID > 99999 || O_ContainerID < 10000) {
			cout << "Error: ContainerID_out of range\n\n";
			continue;
		}
		r = O_ContainerID / 10000;
		dr = O_ContainerID / 1000;
		con = O_ContainerID % 100;
		if (con < 100 && con > 9) {
			if (r == O_RoomID) {
				if (dr == O_DrawerID) {
					break;
				}
				else {
					cout << "Error: Label_Check DrawerID\n\n";
				}
			}
			else {
				cout << "Error: Label_Check RoomID\n\n";
			}
		}
		else {
			cout << "Error: Out_of_range\n\n";
		}
	} while (true);
}

void ItemType::SetDrawerIDFromKB() {
	do {
		cout << "(R: RoomID(1~9), DD: DrawerID(10~99))\n";
		cout << "DrawerID(RDD): ";
		cin >> O_DrawerID;
		if (O_DrawerID > 999 || O_DrawerID < 100) {
			cout << "Error: O_DrawerID_out of range\n\n";
			continue;
		}
		else {
			if (O_DrawerID % 100 > 10) {
				if (O_DrawerID / 100 == O_RoomID) {
					break;
				}
				else {
					cout << "Error: Label_Check RoomID\n\n";
				}
			}
			else {
				cout << "Error: Out_of_range\n\n";
			}
		}
	} while (true);
}

void ItemType::SetRoomIDFromKB() {
	do {
		cout << "RoomID(1~9): ";
		cin >> O_RoomID;
		if (O_RoomID > 9 || O_RoomID < 1) {
			cout << "Error: O_RoomID_out of range\n\n";
		}
		else {
			break;
		}
	} while (true);
}
void ItemType::SetPictureFromKB() {
	cout << "Location of Object Picture: ";
	cin >> O_Picture;
}

void ItemType::SetRecordFromKB() {
	SetNameFromKB();
	SetRoomIDFromKB();
	SetDrawerIDFromKB();
	SetContainerIDFromKB();
	SetLabelFromKB();
	SetTypeFromKB();
	SetDateFromKB();
	SetVolumeFromKB();
	SetPictureFromKB();
}

void ItemType::SetTempfromKB() {
	SetNameFromKB();
	SetTempLabelFromKB();
	SetTypeFromKB();
	SetDateFromKB();
	SetVolumeFromKB();
	SetPictureFromKB();
}

int ItemType::ReadDataFromFile(ifstream& fin) {
	if (fin.is_open()) {
		fin >> O_Name;
		fin >> O_RoomID;
		fin >> O_DrawerID;
		fin >> O_ContainerID;
		fin >> O_Label;
		fin >> O_Type;
		fin >> O_BuyDate;
		fin >> O_Volume;
		fin >> O_Picture;
		return 1;
	}
	else {
		return 0;
	}
}

int ItemType::WriteDataToFile(ofstream& fout) {
	if (fout.is_open()) {
		fout << O_Name << ' ';
		fout << O_RoomID << ' ';
		fout << O_DrawerID << ' ';
		fout << O_ContainerID << ' ';
		fout << O_Label << ' ';
		fout << O_Type << ' ';
		fout << O_BuyDate << ' ';
		fout << O_Volume << ' ';
		fout << O_Picture << '\n';
		return 1;
	}
	else {
		return 0;
	}
}