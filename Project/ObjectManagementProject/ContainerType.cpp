#include "pch.h"
#include "ContainerType.h"

ContainerType::ContainerType() {
	C_ID = 0;
	C_Type = "";
	numOfitem = 0;
	C_Photo = "None";
	C_Name = "";
}

int ContainerType::GetContainerID() const {
	return C_ID;
}

int ContainerType::GetDrawerID() {
	return (C_ID % 10000) / 100;
}

int ContainerType::GetRoomID() {
	return C_ID / 10000;
}

string ContainerType::GetContainerName() const {
	return C_Name;
}

string ContainerType::GetContainerType() const {
	return C_Type;
}

string ContainerType::GetContainerPhoto() const {
	return C_Photo;
}

int ContainerType::GetNumOfItem() const {
	return numOfitem;
}

void ContainerType::SetContainerID(int inID) {
	C_ID = inID;
}

void ContainerType::SetContainerName(string inName) {
	C_Name = inName;
}

void ContainerType::SetContainerType(string inType) {
	C_Type = inType;
}

void ContainerType::SetContainerPhoto(string inPhoto) {
	C_Photo = inPhoto;
}

void ContainerType::SetContainerRecord(int inID, string inName, string inType, string inPhoto) {
	SetContainerID(inID);
	SetContainerName(inName);
	SetContainerType(inType);
	SetContainerPhoto(inPhoto);
}

void ContainerType::SetContainerIDfromKB() {
	int ro, dr, con;
	do {
		cout << "(R: RoomID(1~9), DD: DrawerID(10~99), CC: ContainerID(10~99))\n";
		cout << "ContainerID(RDDCC): ";
		cin >> C_ID;
		if (C_ID > 99999 || C_ID < 10000) {
			cout << "Error: ContainerID_out of range\n\n";
			continue;
		}
		con = C_ID % 100;
		dr = (C_ID % 10000) / 100;
		ro = C_ID / 10000;
		if (con > 99 || con < 10) {
			cout << "Error: Out_of_range\n\n";
			continue;
		}
		if (dr > 99 || dr < 10) {
			cout << "Error: Out_of_range\n\n";
			continue;
		}
		if (ro > 9 || ro < 1) {
			cout << "Error: Out_of_range\n\n";
			continue;
		}
		break;
	} while (true);
}

void ContainerType::SetContainerNamefromKB() {
	cout << "ContainerName: ";
	cin >> C_Name;
}

void ContainerType::SetContainerTypefromKB() {
	cout << "Container Type: ";
	cin >> C_Type;
}
void ContainerType::SetContainerPhotofromKB() {
	cout << "Container Photo: ";
	cin >> C_Photo;
}

void ContainerType::SetContainerRecordfromKB() {
	SetContainerIDfromKB();
	SetContainerNamefromKB();
	SetContainerTypefromKB();
	SetContainerPhotofromKB();
}

int ContainerType::AddItem(const SimpleItemType& data) {
	if (ItemList.Add(data)) {
		numOfitem++;
		return 1;
	}
	return 0;
}

int ContainerType::DeleteItem(SimpleItemType& data) {
	if (ItemList.Delete(data)) {
		numOfitem--;
		return 1;
	}
	return 0;
}

int ContainerType::UpdateItem(SimpleItemType& data) {
	if (ItemList.Replace(data)) {
		return 1;
	}
	return 0;
}

int ContainerType::GetItem(SimpleItemType& data) {
	if (ItemList.Get(data)) {
		return 1;
	}
	return 0;
}

void ContainerType::DisplayAllItem() {
	SimpleItemType temp;
	ItemList.ResetList();
	int pointer = ItemList.GetNextItem(temp);
	while (pointer != -1) {
		cout << pointer + 1 << ".\n";		//가독성을 위해 번호 부여
		temp.DisplayItem();
		pointer = ItemList.GetNextItem(temp);
	}
}

void ContainerType::DisplayContainer() {
	cout << "ContainerID: " << GetContainerID() << endl;
	cout << "Location: " << GetContainerName() << endl;
	cout << "Type: " << GetContainerType() << endl;
	cout << "Photo: " << GetContainerPhoto() << endl;
}

void ContainerType::MakeConatinerEmpty() {
	ItemList.MakeEmpty();
}

//void ContainerType::GetItemByIndex(SimpleItemType& data, int idx) const {
//	ItemList.GetItemByIndex(data, idx);
//}
//