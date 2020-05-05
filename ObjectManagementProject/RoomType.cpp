#include "pch.h"
#include "RoomType.h"

int RoomType::GetRoomID() const {
	return r_ID;
}

string RoomType::GetRoomName() const {
	return r_Name;
}

int RoomType::GetNumOfDrawer() const {
	return r_Length;
}

void RoomType::SetRoomID(int inID) {
	r_ID = inID;
}

void RoomType::SetRoomName(string inName) {
	r_Name = inName;
}

void RoomType::SetRoomRecord(int inID, string inName) {
	r_ID = inID;
	r_Name = inName;
}

void RoomType::SetRoomIDfromKB() {
	do {
		cout << "RoomID(1~9): ";
		cin >> r_ID;
		if (r_ID > 9 || r_ID < 1) {
			cout << "Error: Out_of_range\n";
			continue;
		}
		break;
	} while (1);
}

void RoomType::SetRoomNamefromKB() {
	cout << "RoomName: ";
	cin >> r_Name;
}

int RoomType::AddDrawer(DrawerType& data) {
	if (r_Array.Add(data)) {
		r_Length++;
		return 1;
	}
	return 0;
}

int RoomType::DeleteDrawer(DrawerType& data) {
	if (r_Array.Delete(data)) {
		r_Length--;
		return 1;
	}
	return 0;
}

int RoomType::UpdateDrawer(DrawerType& data) {
	if (r_Array.Replace(data)) {
		return 1;
	}
	return 0;
}

int RoomType::GetDrawer(DrawerType& data) {
	if (r_Array.Get(data)) {
		return 1;
	}
	return 0;
}

void RoomType::DisplayAllDrawer() {
	DrawerType temp;
	r_Array.ResetList();
	r_curPointer = r_Array.GetNextItem(temp);
	while (r_curPointer != -1) {
		cout << "\t######   Drawer   ######\n\n";
		cout << r_curPointer + 1 << ".\n";
		temp.DisplayInfo();
		cout << "\t###### Container  ######\n\n";
		temp.DisplayAllContainer();
		cout << setfill('#') << setw(30) << "\n";
		r_curPointer = r_Array.GetNextItem(temp);
	}

}

void RoomType::DisplayInfo() {
	cout << "RoomID: " << GetRoomID() << endl;
	cout << "RoomName: " << GetRoomName() << endl;
}

void RoomType::ResetList() {
	r_curPointer = -1;
}

void RoomType::MakeEmpty() {
	ResetList();
	r_Length = 0;
	r_Array.MakeEmpty();
}

int RoomType::GetNextDrawer(DrawerType& data) {
	r_curPointer = r_Array.GetNextItem(data);
	return r_curPointer;
}