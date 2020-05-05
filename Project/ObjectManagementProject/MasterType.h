#pragma once
#include "pch.h"

//전체적인 물건의 정보를 담고 있는 class
class MasterType : public Base {
private:
	DoublySortedLinkedList<ItemType> M_List;
	int M_length;
	ifstream a_inFile;
	ofstream a_outFile;
public:
	MasterType();					//생성자
	~MasterType(){}					//소멸자

	/*
	@brief: List에 Object추가
	@pre: Set ItemType for add
	@post: 물건 리스트에 물건을 추가하고, 리스트 크기를 1 늘림. 이미 있는 물건이라면 추가하지 않음
	@return: 물건이 추가가 됐다면 1, 아니면 0을 반환
	*/
	int AddObject(ItemType& data);

	/*
	@brief: List에서 Object삭제
	@pre: Set ObjectID for delete. Object exist in List
	@post: 물건 리스트에서 해당하는 물건을 삭제하고, 리스트 크기를 1 줄임
	@return: 물건이 삭제가 됐다면 1, 아니면 0을 반환
	*/
	int DeleteObject(ItemType& data);

	/*
	@brief: List에서 Object의 정보를 수정
	@pre: Set ItemType for update. Object exist in List
	@post: 물건 리스트에서 해당하는 물건의 정보를 수정함
	@return: 물건의 정보가 수정 됐다면 1, 아니면 0을 반환
	*/
	int UpdateObject(const ItemType& data);

	/*
	@brief: 해당하는 물건의 정보를 화면에 display
	@pre: Object alredy exist. Set ObjectID for find
	@post: 해당하는 물건의 검색횟수가 증가하고, Best_List에 추가될지 검사함
	@return: 물건의 정보를 얻고, 검색횟수가 증가된다면 1을 반환, 아니면 0을 반환
	*/
	int GetObject(ItemType& data);

	/*
	@brief: 물건의 정보를 이름으로 찾고, 화면에 display
	@pre: Object alredy exist. Set ObjectName for find
	@post: 해당하는 물건의 검색횟수가 증가하고, Best_List에 추가될지 검사함
	@return: 물건의 정보를 얻고, 검색횟수가 증가된다면 1을 반환, 아니면 0을 반환
	*/
	int GetObjectByName(ItemType& data);

	/*
	@brief: 물건의 정보를 용도로 찾고 화면에 display
	@pre: Object alredy exist. Set ObjectType for find
	@post: 해당하는 물건의 검색횟수가 증가하고, Best_List에 추가될지 검사함
	@return: 물건의 정보를 얻고, 검색횟수가 증가된다면 1을 반환, 아니면 0을 반환
	*/
	int GetObjectByUsage(ItemType& data);

	/*
	@brief: 물건의 정보를 구매시기로 찾고 화면에 display
	@pre: Object alredy exist. Set ObjectType for find
	@post: 해당하는 물건의 검색횟수가 증가하고, Best_List에 추가될지 검사함
	@return: 물건의 정보를 얻고, 검색횟수가 증가된다면 1을 반환, 아니면 0을 반환
	*/
	int GetObjectByBuydate(int start, int finish);

	/*
	@brief: 모든 물건의 정보를 화면에 display
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