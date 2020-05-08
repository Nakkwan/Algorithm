#pragma once
#include "pch.h"
using namespace std;
class Employee {
private:
	int E_age;
	string E_number;
	int E_skill;
	string E_name;
	int E_money;
	int E_rank;
	int E_prefer;

public:
	Employee() {
		E_age = -1;
		E_number = "";
		E_skill = -1;
		E_name = "";
		E_money = -1;
		E_rank = -1;
		E_prefer = -1;
	}
	~Employee(){}

	/*
	@brief: ���̸� ��ȯ�޴´�.
	@pre: set Age
	@post: none
	*/
	int GetAge() const;

	/*
	@brief: ���õ��� ��ȯ�޴´�.
	@pre: set skill
	@post: none
	*/
	int GetSkill() const;

	/*
	@brief: ��� �ϴ縦 ��ȯ�޴´�.
	@pre: set money
	@post: none
	*/
	int GetMoney() const;

	/*
	@brief: ��� ������ ��ȯ�޴´�.
	@pre: set rank
	@post: none
	*/
	int GetRank() const;

	/*
	@brief: ��ȭ��ȣ�� ��ȯ�޴´�.
	@pre: set phone number
	@post: none
	*/
	string GetNumber() const;

	/*
	@brief: �̸� ��ȯ�޴´�.
	@pre: set name
	@post: none
	*/
	string GetName() const;

	/*
	@brief: ���� �о߸� ��ȯ�޴´�.
	@pre: set prefer
	@post: none
	*/
	int GetPrefer() const;

	/*
	@brief: ���̸� �����Ѵ�.
	@pre: none
	@post: assigned age
	@param: age for assign
	*/
	void SetAge(int inage);

	/*
	@brief: ���õ��� �����Ѵ�.
	@pre: none
	@post: assigned skill
	@param: skill for assign
	*/
	void SetSkill(int inskill);

	/*
	@brief: ��� �ϴ縦 �����Ѵ�.
	@pre: none
	@post: assigned money
	@param: money for assign
	*/
	void SetMoney(int inmoney);

	/*
	@brief: ��� ������ �����Ѵ�.
	@pre: none
	@post: assigned rank
	@param: rank for assign
	*/
	void SetRank(int inrank);

	/*
	@brief: ��ȭ ��ȣ�� �����Ѵ�.
	@pre: none
	@post: assigned phone number
	@param: phone number for assign
	*/
	void SetNumber(string innumber);

	/*
	@brief: �̸��� �����Ѵ�.
	@pre: none
	@post: assigned name
	@param: name for assign
	*/
	void SetName(string inname);

	/*
	@brief: ���� �о߸� �����Ѵ�.
	@pre: none
	@post: assigned prefer
	@param: prefer for assign
	*/
	void SetPrefer(int inprefer);

	/*
	@brief: �������� ���̸� Ű����κ��� �޴´�.
	@pre: none
	@post: assign age
	*/
	void SetAgeFromKB();

	/*
	@brief: �������� ���õ��� Ű����κ��� �޴´�.
	@pre: none
	@post: assign skill
	*/
	void SetSkillFromKB();

	/*
	@brief: �������� ��� �ϴ縦 Ű����κ��� �޴´�.
	@pre: none
	@post: assign money
	*/
	void SetMoneyFromKB();

	/*
	@brief: �������� ��ȭ��ȣ�� Ű����κ��� �޴´�.
	@pre: none
	@post: assign phone number
	*/
	void SetNumberFromKB();

	/*
	@brief: �������� �̸��� Ű����κ��� �޴´�.
	@pre: none
	@post: assign Name
	*/
	void SetNameFromKB();

	/*
	@brief: �������� ���� �о߸� Ű����κ��� �޴´�.
	@pre: none
	@post: assign Name
	*/
	void SetPreferFromKB();

	/*
	@brief: �������� ������ Ű����κ��� �޴´�.
	@pre: none
	@post: assign member value
	*/
	void SetRecordFromKB();


	/*
	@brief: ��ü�� ������ ���Ϸκ��� �޴´�.
	@pre: file is valid
	@post: member value is assigned from file data
	@param: valid file for get data
	*/
	int ReadDataFromFile(ifstream& fin);

	/*
	@brief: ��ü�� ������ ���Ϸ� ��������.
	@pre: set member value
	@post: ���Ͽ� ��ü�� ������ ��������.
	@param: valid file
	*/
	int WriteDataToFile(ofstream& fout);

	/*
	@brief: ��ü�� ������ ȭ�鿡 display
	@pre: set object
	@post: none
	*/
	void DisplayOnScreen();

	/*
	@brief: �Է¹��� ��ü�� ���� ��ü�� �Ҵ�
	@pre: set Object for assign
	@post: member value are assigned
	*/
	void operator=(const Employee& data) {
		E_age = data.GetAge();
		E_money = data.GetMoney();
		E_name = data.GetName();
		E_number = data.GetNumber();
		E_rank = data.GetRank();
		E_skill = data.GetSkill();
		E_prefer = data.GetPrefer();
	}

	/*
	@brief: �� ��ü�� ������ Ȯ��
	@pre: set object for compare
	@post: none
	@return: �� ��ü�� ��� ������ ������ 1, �ƴϸ� 0�� ��ȯ
	*/
	bool operator==(const Employee& data) {
		if (E_rank == data.GetRank()) {
			return true;
		}
		else {
			return false;
		}
	}
};