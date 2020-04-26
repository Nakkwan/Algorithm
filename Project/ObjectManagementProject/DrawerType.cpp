#include "DrawerType.h"

int DrawerType::GetDrawerID() const{
	return d_ID;
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
	cout << "DrawerID: ";
	cin >> d_ID;
}

void DrawerType::SetDrawerNamefromKB() {
	cout << "DrawerName: ";
	cin >> d_Name;
}

void DrawerType::SetDrawerTypefromKB() {
	cout << "DrawerType: ";
	cin >> d_type;
}

void DrawerType::AddContainer(const ContainerType& data) {
	if (d_Array.Add(data)) {
		d_length++;
	}
}

void DrawerType::DeleteContainer(ContainerType& data) {
	if (d_Array.Delete(data)) {
		d_length--;
	}
}

void DrawerType::UpdateContainer(ContainerType& data) {
	d_Array.Replace(data);
}

void DrawerType::DisplayAllContainer() {
	ContainerType temp;
	int d_curPointer = d_Array.GetNextItem(temp);
	while (d_curPointer != -1) {
		cout << d_curPointer + 1 << ".\n";
		temp.DisplayContainer();
		temp.DisplayAllItem();
		temp.DisplayAllPhoto();
	}
}

void DrawerType::DisplayInfo() {
	cout << "\t\t<Drawer Information>>\n";
	cout << "DrawerID: " << GetDrawerID() << endl;
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