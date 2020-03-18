#include "ItemType.h"

int ItemType::GetId() {
	return m_Id;
}

string ItemType::GetName() {
	return m_sName;
}

string ItemType::GetAddress() {
	return m_sAddress;
}

void ItemType::SetId(int inId) {
	m_Id = inId;
}

void ItemType::SetName(string inName) {
	m_sName = inName;
}

void ItemType::SetAddress(string inAddress) {
	m_sAddress = inAddress;
}

void ItemType::SetRecord(int inId, string inName, string inAddress) {
	m_Id = inId;
	m_sName = inName;
	m_sAddress = m_sAddress;
}

void ItemType::DisplayIdOnScreen() {
	cout << GetId() << endl;
}

void ItemType::DisplayNameOnScreen() {
	cout << GetName() << endl;
}

void ItemType::DisplayAddressOnScreen() {
	cout << GetAddress() << endl;
}

void ItemType::DisplayRecordOnScreen() {
	cout << "ID: " << GetId() << '\n';
	cout << "Name: " << GetName() << '\n';
	cout << "Address: " << GetAddress() << '\n';
}

void ItemType::SetIdFromKB() {
	cout << "ID: ";
	cin >> m_Id;
}

void ItemType::SetNameFromKB() {
	cout << "Name: ";
	cin >> m_sName;
}

void ItemType::SetAddressFromKB() {
	cout << "Adrress: ";
	cin >> m_sAddress;
}

void ItemType::SetRecordFromKB() {
	SetIdFromKB();
	SetNameFromKB();
	SetAddressFromKB();
}

int ItemType::ReadDataFromFile(ifstream& fin) {
	fin >> m_Id;
	fin >> m_sName;
	fin >> m_sAddress;

	return 1;
}

int ItemType::WriteDataToFile(ofstream& fout) {
	if (fout.is_open()) {
		fout << m_Id << ' ';
		fout << m_sName << ' ';
		fout << m_sAddress << '\n';

		return 1;
	}
	else {
		return 0;
	}
}

RelationType ItemType::CompareByID(ItemType data) {
	if (this->GetId() > data.GetId()) {
		return GREATER;
	}else if (this->GetId() == data.GetId()) {
		return EQUAL;
	}else if (this->GetId() < data.GetId()) {
		return LESS;
	}
}