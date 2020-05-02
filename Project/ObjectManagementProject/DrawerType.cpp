#include "pch.h"
#include "DrawerType.h"

DrawerType::DrawerType() {
	d_ID = -1;
	d_length = 0;
	d_type = "";
	d_Name = "";
	d_curPointer = -1;
}

int DrawerType::GetDrawerID() const{
	return d_ID;
}

int DrawerType::GetRoomID() {
	return d_ID / 100;
}

string DrawerType::GetDrawerName() const{
	return d_Name;
}

string DrawerType::GetDrawerType() const{
	return d_type;
}

int DrawerType::GetNumOfContainer() const{
	return d_length;
}

void DrawerType::SetDrawerID(int inID){
	d_ID = inID;
}

void DrawerType::SetDrawerName(string inName){
	d_Name = inName;
}

void DrawerType::SetDrawerType(string inType){
	d_type = inType;
}

void DrawerType::SetDrawerRecord(int inID, string inName, string inType) {
	d_ID = inID;
	d_Name = inName;
	d_type = inType;
}

void DrawerType::SetDrawerIDfromKB() {
	int ro, dr;
	do {
		cout << "(R: RoomID(1~9), DD: DrawerID(10~99))\n";
		cout << "DrawerID(RDD): ";
		cin >> d_ID;
		if (d_ID > 999 || d_ID < 100) {
			cout << "Error: DrawerID_out of range\n\n";
			continue;
		}
		ro = d_ID / 100;
		dr = d_ID % 100;
		if (dr < 100 && dr > 9) {
			if (ro < 10 && ro > 1) {
				break;
			}
			else {
				cout << "Error: Out_of_range\n\n";
			}
		}
		else {
			cout << "Error: Out_of_range\n\n";
		}
	} while (true);
}

void DrawerType::SetDrawerNamefromKB() {
	cout << "DrawerName: ";
	cin >> d_Name;
}

void DrawerType::SetDrawerTypefromKB() {
	cout << "DrawerType: ";
	cin >> d_type;
}

int DrawerType::AddContainer(const ContainerType& data) {
	if (d_Array.Add(data)) {
		d_length++;
		return 1;
	}
	return 0;
}

int DrawerType::DeleteContainer(ContainerType& data) {
	if (d_Array.Delete(data)) {
		d_length--;
		return 1;
	}
	return 0;
}

int DrawerType::UpdateContainer(ContainerType& data) {
	if (d_Array.Replace(data)) {
		return 1;
	}
	return 0;
}

int DrawerType::GetContainer(ContainerType& data) {
	if (d_Array.Get(data)) {
		return 1;
	}
	return 0;
}

void DrawerType::DisplayAllContainer() {
	ContainerType temp;
	int d_curPointer = d_Array.GetNextItem(temp);
	while (d_curPointer != -1) {
		cout << d_curPointer + 1 << ".\n";
		temp.DisplayContainer();
		cout << "\t######   Object   ######\n\n";
		temp.DisplayAllItem();
	}
}

void DrawerType::DisplayInfo() {
	cout << "DrawerID(RDD): " << GetDrawerID() << endl;
	cout << "DrawerName: " << GetDrawerName() << endl;
	cout << "DrawerType: " << GetDrawerType() << endl;
}

void DrawerType::ResetList() {
	d_curPointer = -1;
}

int DrawerType::GetNextContainer(ContainerType& data) {
	d_curPointer = d_Array.GetNextItem(data);
	return d_curPointer;
}

void DrawerType::MakeEmpty() {
	ResetList();
	d_Array.MakeEmpty();
}