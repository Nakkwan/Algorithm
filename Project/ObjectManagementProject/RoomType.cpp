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
		}
	} while (r_ID < 10 && r_ID > 0);
}

void RoomType::SetRoomNamefromKB() {
	cout << "RoomName: ";
	cin >> r_Name;
}

void RoomType::AddDrawer(const DrawerType& data) {
	if (r_Array.Add(data)) {
		r_Length++;
	}
}

void RoomType::DeleteDrawer(DrawerType& data) {
	if (r_Array.Delete(data)) {
		r_Length--;
	}
}

void RoomType::UpdateDrawer(DrawerType& data) {
	r_Array.Replace(data);
}

void RoomType::DiplayAllDrawer() {
	DrawerType temp;
	r_curPointer = r_Array.GetNextItem(temp);
	while (r_curPointer != -1) {
		cout << r_curPointer + 1 << ".\n";
		temp.DisplayInfo();
		temp.DisplayAllContainer();
	}

}

void RoomType::DisplayInfo() {
	cout << "RoomID: " << GetRoomID() << endl;
	cout << "RoomName: " << GetRoomName() << endl;
}