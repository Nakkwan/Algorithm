#pragma once
#include "pch.h"

//��ü���� ������ ������ ��� �ִ� class
class MasterType : public Base {
private:
	DoublySortedLinkedList<ItemType> M_List;
	int M_length;
	ifstream a_inFile;
	ofstream a_outFile;
public:
	MasterType();					//������
	~MasterType(){}					//�Ҹ���

	/*
	@brief: List�� Object�߰�
	@pre: Set ItemType for add
	@post: ���� ����Ʈ�� ������ �߰��ϰ�, ����Ʈ ũ�⸦ 1 �ø�. �̹� �ִ� �����̶�� �߰����� ����
	@return: ������ �߰��� �ƴٸ� 1, �ƴϸ� 0�� ��ȯ
	*/
	int AddObject(ItemType& data);

	/*
	@brief: List���� Object����
	@pre: Set ObjectID for delete. Object exist in List
	@post: ���� ����Ʈ���� �ش��ϴ� ������ �����ϰ�, ����Ʈ ũ�⸦ 1 ����
	@return: ������ ������ �ƴٸ� 1, �ƴϸ� 0�� ��ȯ
	*/
	int DeleteObject(ItemType& data);

	/*
	@brief: List���� Object�� ������ ����
	@pre: Set ItemType for update. Object exist in List
	@post: ���� ����Ʈ���� �ش��ϴ� ������ ������ ������
	@return: ������ ������ ���� �ƴٸ� 1, �ƴϸ� 0�� ��ȯ
	*/
	int UpdateObject(const ItemType& data);

	/*
	@brief: �ش��ϴ� ������ ������ ȭ�鿡 display
	@pre: Object alredy exist. Set ObjectID for find
	@post: �ش��ϴ� ������ �˻�Ƚ���� �����ϰ�, Best_List�� �߰����� �˻���
	@return: ������ ������ ���, �˻�Ƚ���� �����ȴٸ� 1�� ��ȯ, �ƴϸ� 0�� ��ȯ
	*/
	int GetObject(ItemType& data);

	/*
	@brief: ������ ������ �̸����� ã��, ȭ�鿡 display
	@pre: Object alredy exist. Set ObjectName for find
	@post: �ش��ϴ� ������ �˻�Ƚ���� �����ϰ�, Best_List�� �߰����� �˻���
	@return: ������ ������ ���, �˻�Ƚ���� �����ȴٸ� 1�� ��ȯ, �ƴϸ� 0�� ��ȯ
	*/
	int GetObjectByName(ItemType& data);

	/*
	@brief: ������ ������ �뵵�� ã�� ȭ�鿡 display
	@pre: Object alredy exist. Set ObjectType for find
	@post: �ش��ϴ� ������ �˻�Ƚ���� �����ϰ�, Best_List�� �߰����� �˻���
	@return: ������ ������ ���, �˻�Ƚ���� �����ȴٸ� 1�� ��ȯ, �ƴϸ� 0�� ��ȯ
	*/
	int GetObjectByUsage(ItemType& data);

	/*
	@brief: ������ ������ ���Žñ�� ã�� ȭ�鿡 display
	@pre: Object alredy exist. Set ObjectType for find
	@post: �ش��ϴ� ������ �˻�Ƚ���� �����ϰ�, Best_List�� �߰����� �˻���
	@return: ������ ������ ���, �˻�Ƚ���� �����ȴٸ� 1�� ��ȯ, �ƴϸ� 0�� ��ȯ
	*/
	int GetObjectByBuydate(int start, int finish);

	/*
	@brief: ��� ������ ������ ȭ�鿡 display
	@pre: none
	@post: none
	*/
	int DisplayAllObject();

	/*
	@brief:	Open a file by file descriptor as an input file.
	@pre: a file for reading is exist.
	@post: open the file for reading.
	@param:	filename to open for reading.
	@return: return 1 if this function works well, otherwise 0.
	*/
	int OpenInFile(char* filename);

	/*
	@brief:	Open a file by file descriptor as an output file.
	@pre: list should be initialized.
	@post: open the file for writing.
	@param: filename to open for writing.
	@return: return 1 if this function works well, otherwise 0.
	*/
	int OpenOutFile(char* filename);

	/*
	@brief:	Open a file as a read mode, read all data on the file, and set list by the data.
	@pre: The file is not opened.
	@post: list holds all records from the file.
	@return: return 1 if this function works well, otherwise 0.
	*/
	int ReadDataFromFile();

	/*
	@brief:Open a file as a write mode, and write all data into the file,
	@pre: The file is not opened.
	@post: the list is stored in the output file.
	@return: return 1 if this function works well, otherwise 0.
	*/
	int WriteDataToFile();
};