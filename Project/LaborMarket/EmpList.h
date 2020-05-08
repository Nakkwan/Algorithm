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
	@brief: ����Ʈ�� ������ �߰�
	@pre: set information of Employee
	@post: �������� ��Ϲ�ȣ�� �����ǰ� ����Ʈ�� �����ڰ� �߰��ȴ�.
	@return: �߰��� �����ϸ� 1, �ƴϸ� 0�� ��ȯ
	*/
	int Add(Employee& data);

	/*
	@brief: ����Ʈ�� ������ ����
	@pre: ������ ������ �����Ѵ�.
	@post: �ش��ϴ� ������ ����Ʈ���� �����ȴ�.
	@return: ������ �����ϸ� 1, �ƴϸ� 0�� ��ȯ
	*/
	int Delete(Employee& data);

	/*
	@brief: ����Ʈ�� ������ ��� display�Ѵ�.
	@pre: none
	@post: none
	*/
	void Display();

	/*
	@brief: ����Ʈ���� �̸����� ������ �˻��Ѵ�.
	@pre: �˻��� �̸��� �����Ѵ�.
	@post: none
	@return: ������ ��������� 1, �ƴϸ� 0�� ��ȯ
	*/
	int SearchByName(Employee& data);

	/*
	@brief: ����Ʈ���� ���õ��� ������ �˻��Ѵ�.
	@pre: ���ϴ� ���õ� �����Ѵ�.
	@post: none
	@return: ������ ��������� 1, �ƴϸ� 0�� ��ȯ
	*/
	int SearchBySkill(Employee& data);

	/*
	@brief: ����Ʈ���� ���� �о߷� ������ �˻��Ѵ�.
	@pre: ���ϴ� ���� �о߸� �����Ѵ�.
	@post: none
	@return: ������ ��������� 1, �ƴϸ� 0�� ��ȯ
	*/
	int SearchByPrefer(Employee& data);


	/*
	@brief: ����ְ� ����ϴ� ������ �̸��� �޾�, ����ϰ�, ����Ʈ���� �����Ѵ�.
	@pre: set name of prefer employee
	@post: ����Ʈ���� �ش� ������ �����ǰ�, display�ȴ�.
	@return: �ش� �����ڸ� ã��, display�ϰ� �����ϸ� 1 �ƴϸ� 0�� ��ȯ
	*/
	int PickByName(Employee& data);

	/*
	@brief: ����ְ� ����ϴ� ������ ������ �޾�, ����ϰ�, ����Ʈ���� �����Ѵ�.
	@pre: set information of prefer employee
	@post: ����Ʈ���� �ش� ������ �����ǰ�, display�ȴ�.
	@return: ����� ������ ������ ��ȯ�Ѵ�.
	*/
	int PickEmployee(Employee& data, int size, int from, int to, bool prefer);

	/*
	@brief: ��� ������ ������ ���� ������ �����Ѵ�.
	@pre: ������� ����ϴ� ������ ������ �����Ѵ�.
	@post: ��� ������ ���� ������ ScoreList�� �߰��ȴ�.
	@return: �߰��� �����ϸ� 1 �ƴϸ� 0�� ��ȯ�Ѵ�.
	*/
	int SetScore(Employee& data, bool prefer);

	/*
	@brief: �� ������ �ش��ϴ� �����ڸ� size��ŭ ����ϰ� ����Ʈ���� �����Ѵ�.
	@pre: set size
	@post: ����Ʈ���� �ش� ������ �����ǰ�, display�ȴ�.
	@return: ����� ������ ������ ��ȯ�Ѵ�.
	*/
	int PickByScore(int size);

	/*
	@brief: ����Ʈ�� �����ڵ��� ��� ������ �������ȴ�.
	@pre: none
	@post: �����ڵ��� ��� ������ �������ȴ�.
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
	@brief:	���Ϸκ��� �����͸� �Է¹޴´�.
	@pre: ������ ������ �Ѵ�.
	@post: ���Ϸκ��� ���� �����Ͱ� ����Ʈ�� �߰��ȴ�.
	@return: ������ �б�� �߰��� �����ϸ� 1, �ƴϸ� 0�� ��ȯ
	*/
	int ReadDataFromFile();

	/*
	@brief: ����Ʈ�� ������ ���Ͽ� ����.
	@pre: ������ ������ �Ѵ�.
	@post: ����Ʈ�� ������ ���Ͽ� ����.
	@return: ���Ͽ� ���� �Ϳ� �����ϸ� 1, �ƴϸ� 0�� ��ȯ
	*/
	int WriteDataToFile();
};