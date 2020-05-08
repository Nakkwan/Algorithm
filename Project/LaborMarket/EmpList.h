#pragma once
#include "pch.h"

class EmpList : public Base {
private:
	UnsortedLinkedList<Employee> E_List;
	int E_length;
	ifstream E_inFile;
	ofstream E_outFile;

public:
	EmpList() {
		E_length = 0;
	}
	~EmpList(){}

	/*
	@brief: 리스트에 구직자 추가
	@pre: set information of Employee
	@post: 구직자의 등록번호가 설정되고 리스트에 구직자가 추가된다.
	@return: 추가에 성공하면 1, 아니면 0을 반환
	*/
	int Add(Employee& data);

	/*
	@brief: 리스트에 구직자 삭제
	@pre: 삭제할 정보를 설정한다.
	@post: 해당하는 정보가 리스트에서 삭제된다.
	@return: 삭제에 성공하면 1, 아니면 0을 반환
	*/
	int Delete(Employee& data);

	/*
	@brief: 리스트의 정보를 모두 display한다.
	@pre: none
	@post: none
	*/
	void Display();

	/*
	@brief: 리스트에서 이름으로 정보를 검색한다.
	@pre: 검색할 이름을 설정한다.
	@post: none
	@return: 정보를 출력했으면 1, 아니면 0을 반환
	*/
	int SearchByName(Employee& data);

	/*
	@brief: 리스트에서 숙련도로 정보를 검색한다.
	@pre: 원하는 숙련도 설정한다.
	@post: none
	@return: 정보를 출력했으면 1, 아니면 0을 반환
	*/
	int SearchBySkill(Employee& data);

	/*
	@brief: 리스트에서 전문 분야로 정보를 검색한다.
	@pre: 원하는 전문 분야를 설정한다.
	@post: none
	@return: 정보를 출력했으면 1, 아니면 0을 반환
	*/
	int SearchByPrefer(Employee& data);


	/*
	@brief: 고용주가 희망하는 구직자 이름을 받아, 출력하고, 리스트에서 삭제한다.
	@pre: set name of prefer employee
	@post: 리스트에서 해당 정보가 삭제되고, display된다.
	@return: 해당 구직자를 찾아, display하고 삭제하면 1 아니면 0을 반환
	*/
	int PickByName(Employee& data);

	/*
	@brief: 고용주가 희망하는 구직자 정보를 받아, 출력하고, 리스트에서 삭제한다.
	@pre: set information of prefer employee
	@post: 리스트에서 해당 정보가 삭제되고, display된다.
	@return: 출력한 정보의 개수를 반환한다.
	*/
	int PickEmployee(Employee& data, int size, int from, int to, bool prefer);

	/*
	@brief: 희망 구직자 정보에 따라 점수를 설정한다.
	@pre: 고용인이 희망하는 구직자 정보를 설정한다.
	@post: 희망 정보에 따른 점수가 ScoreList에 추가된다.
	@return: 추가에 성공하면 1 아니면 0을 반환한다.
	*/
	int SetScore(Employee& data, bool prefer);

	/*
	@brief: 각 점수에 해당하는 구직자를 size만큼 출력하고 리스트에서 삭제한다.
	@pre: set size
	@post: 리스트에서 해당 정보가 삭제되고, display된다.
	@return: 출력한 정보의 개수를 반환한다.
	*/
	int PickByScore(int size);

	/*
	@brief: 리스트의 구직자들의 등록 순위가 재조정된다.
	@pre: none
	@post: 구직자들의 등록 순위가 재조정된다.
	*/
	void RearrangeRank();

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
	@brief:	파일로부터 데이터를 입력받는다.
	@pre: 파일이 열려야 한다.
	@post: 파일로부터 읽은 데이터가 리스트에 추가된다.
	@return: 데이터 읽기와 추가가 성공하면 1, 아니면 0을 반환
	*/
	int ReadDataFromFile();

	/*
	@brief: 리스트의 정보를 파일에 쓴다.
	@pre: 파일이 열려야 한다.
	@post: 리스트의 정보를 파일에 쓴다.
	@return: 파일에 쓰는 것에 성공하면 1, 아니면 0을 반환
	*/
	int WriteDataToFile();
};