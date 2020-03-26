#ifndef ITEMTYPE_H
#define ITEMTYPE_H
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

enum RelationType {LESS, GREATER, EQUAL};

class ItemType {
public:
	ItemType() {// default constructor
		m_Id = 0;
		m_sName = "";
		m_sAddress = "";
	}
	~ItemType() {}
	int GetId() const; 
	string GetName() const; 
	string GetAddress() const;  
	void SetId(int inId); 
	void SetName(string inName); 
	void SetAddress(string inAddress); 
	void SetRecord(int inId, string inName, string inAddress); 
	void DisplayIdOnScreen();
	void DisplayNameOnScreen();
	void DisplayAddressOnScreen();
	void DisplayRecordOnScreen(); 
	void SetIdFromKB(); 
	void SetNameFromKB(); 
	void SetAddressFromKB(); 
	void SetRecordFromKB(); 
	int ReadDataFromFile(std::ifstream& fin); 
	int WriteDataToFile(std::ofstream& fout);
	RelationType CompareByID(ItemType data); 
	bool operator==(const ItemType& data) {
		if (m_Id == data.GetId()) {
			return true;
		}
		else {
			return false;
		}
	}

	void operator=(const ItemType& data) {
		m_Id = data.GetId();
		m_sName = data.GetName();
		m_sAddress = data.GetAddress();
	}

private:
	int m_Id; // 학생 ID 
	string m_sName; // 학생 이름 저장 변수 
	string m_sAddress; // 학생 주소 저장 변수
};

#endif
