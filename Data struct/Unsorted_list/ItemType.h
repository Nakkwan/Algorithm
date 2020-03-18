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
	int GetId(); // �л� ID ��ȯ �Լ�
	string GetName(); // �л� �̸� ��ȯ �Լ�
	string GetAddress(); // �л� �ּ� ��ȯ �Լ� 
	void SetId(int inId); // �л� ID ���� �Լ�
	void SetName(string inName); // �л� �̸� ���� �Լ� 
	void SetAddress(string inAddress); // �л� �ּ� ���� �Լ�
	void SetRecord(int inId, string inName, string inAddress); // �л� ���� ���� �Լ�
	void DisplayIdOnScreen(); // �л� ID ��� �Լ� 
	void DisplayNameOnScreen(); // �л� �̸� ��� �Լ�
	void DisplayAddressOnScreen(); // �л� �ּ� ��� �Լ�
	void DisplayRecordOnScreen(); // �л� ���� ��� �Լ�
	void SetIdFromKB(); // Ű����� �л� ID �Է� �Լ� 
	void SetNameFromKB(); // Ű����� �л� �̸� �Է� �Լ� 
	void SetAddressFromKB(); // Ű����� �л� �ּ� �Է� �Լ� 
	void SetRecordFromKB(); // Ű����� �л� ���� �Է� �Լ�
	int ReadDataFromFile(std::ifstream& fin); // �л� ������ ���Ͽ��� �д� �Լ�
	int WriteDataToFile(std::ofstream& fout); // �л� ������ ���Ϸ� ����ϴ� �Լ�
	RelationType CompareByID(ItemType data); // primary key (ID)�� �������� �л� ������ ���ϴ� �Լ�

private:
	int m_Id; // �л� ID 
	string m_sName; // �л� �̸� ���� ���� 
	string m_sAddress; // �л� �ּ� ���� ����

};

#endif
