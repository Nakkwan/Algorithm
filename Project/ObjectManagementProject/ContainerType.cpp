#include "ContainerType.h"

ContainerType::ContainerType() {
	C_ID = 0;
	C_Type = "";
	numOfitem = 0;
	numOfPhoto = 0;
}

int ContainerType::GetContainerID() const {
	return C_ID;
}

string ContainerType::GetContainerName() const {
	return C_Name;
}

string ContainerType::GetContainerType() const {
	return C_Type;
}

int ContainerType::GetNumOfItem() const {
	return numOfitem;
}

int ContainerType::GetNumOfPhoto() const {
	return numOfPhoto;
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

void ContainerType::SetContainerRecord(int inID, string inName, string inType) {
	SetContainerID(inID);
	SetContainerName(inName);
	SetContainerType(inType);
}

void ContainerType::SetContainerIDfromKB() {
	int r, dr, con;
	do {
		cout << "(R: RoomID(1~9), DD: DrawerID(10~99), CC: ContainerID(10~99))\n";
		cout << "ContainerID(RDDCC): ";
		cin >> C_ID;
		if (C_ID > 99999 || C_ID < 10000) {
			cout << "Error: ContainerID_out of range\n\n";
			continue;
		}
		con = C_ID % 100;
		if (con < 100 && con > 9) {
			break;
		}
		else {
			cout << "Error: Out_of_range\n\n";
		}
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

void ContainerType::SetContainerRecordfromKB() {
	SetContainerIDfromKB();
	SetContainerNamefromKB();
	SetContainerTypefromKB();
}

void ContainerType::AddItem(const SimpleItemType& data) {
	if (ItemList.Add(data)) {
		numOfitem++;
	}
}

void ContainerType::DeleteItem(SimpleItemType& data) {
	if (ItemList.Delete(data)) {
		numOfitem--;
	}
}

void ContainerType::UpdateItem(SimpleItemType data) {
	ItemList.Replace(data);
}

void ContainerType::AddPhoto(string pho) {
	if (photoList.Add(pho)) {
		numOfPhoto++;
	}
}

void ContainerType::DeletePhoto(string pho) {
	if (photoList.Delete(pho)) {
		numOfPhoto--;
	}
}

void ContainerType::UpdatePhoto(string pho) {
	photoList.Replace(pho);
}

void ContainerType::DisplayAllItem() {
	SimpleItemType temp;
	ItemList.ResetList();
	int pointer = ItemList.GetNextItem(temp);
	cout << "\t\t<<ItemList>>\n";
	while (pointer != -1) {
		cout << pointer + 1 << ".\n";		//가독성을 위해 번호 부여
		temp.DisplayItem();
		pointer = ItemList.GetNextItem(temp);
	}
}

void ContainerType::DisplayAllPhoto() {
	string temp;
	photoList.ResetList();
	int pointer = photoList.GetNextItem(temp);
	int S_size = photoList.GetLength();
	cout << "\t<<Location of photo>>\n";
	while (pointer != -1) {
		cout << pointer + 1 << ".\n" << temp << "\n";		//가독성을 위해 번호 부여
		pointer = photoList.GetNextItem(temp);
	}
}

void ContainerType::DisplayContainer() {
	cout << "\t\t<Container Information>>\n";
	cout << "ContainerID: " << GetContainerID() << endl;
	cout << "Location: " << GetContainerName() << endl;
	cout << "Type: " << GetContainerType() << endl;
}

void ContainerType::MakeConatinerEmpty() {
	ItemList.MakeEmpty();
	photoList.MakeEmpty();

}

//void ContainerType::GetItemByIndex(SimpleItemType& data, int idx) const {
//	ItemList.GetItemByIndex(data, idx);
//}
//
//void ContainerType::GetPhotoByIndex(string& data, int idx) const {
//	photoList.GetItemByIndex(data, idx);
//}