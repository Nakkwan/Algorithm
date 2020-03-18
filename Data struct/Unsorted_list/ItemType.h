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
	~ItemType() {} // default destructor
	int GetId(); // 학생 ID 반환 함수
	string GetName(); // 학생 이름 반환 함수
	string GetAddress(); // 학생 주소 반환 함수 
	void SetId(int inId); // 학생 ID 저장 함수
	void SetName(string inName); // 학생 이름 저장 함수 
	void SetAddress(string inAddress); // 학생 주소 저장 함수
	void SetRecord(int inId, string inName, string inAddress); // 학생 정보 저장 함수
	void DisplayIdOnScreen(); // 학생 ID 출력 함수 
	void DisplayNameOnScreen(); // 학생 이름 출력 함수
	void DisplayAddressOnScreen(); // 학생 주소 출력 함수
	void DisplayRecordOnScreen(); // 학생 정보 출력 함수
	void SetIdFromKB(); // 키보드로 학생 ID 입력 함수 
	void SetNameFromKB(); // 키보드로 학생 이름 입력 함수 
	void SetAddressFromKB(); // 키보드로 학생 주소 입력 함수 
	void SetRecordFromKB(); // 키보드로 학생 정보 입력 함수
	int ReadDataFromFile(std::ifstream& fin); // 학생 정보를 파일에서 읽는 함수
	int WriteDataToFile(std::ofstream& fout); // 학생 정보를 파일로 출력하는 함수
	RelationType CompareByID(ItemType data); // primary key (ID)를 기준으로 학생 정보를 비교하는 함수

private:
	int m_Id; // 학생 ID 
	string m_sName; // 학생 이름 저장 변수 
	string m_sAddress; // 학생 주소 저장 변수

};

#endif
