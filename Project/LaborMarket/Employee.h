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
	@brief: 나이를 반환받는다.
	@pre: set Age
	@post: none
	*/
	int GetAge() const;

	/*
	@brief: 숙련도를 반환받는다.
	@pre: set skill
	@post: none
	*/
	int GetSkill() const;

	/*
	@brief: 희망 일당를 반환받는다.
	@pre: set money
	@post: none
	*/
	int GetMoney() const;

	/*
	@brief: 등록 순위를 반환받는다.
	@pre: set rank
	@post: none
	*/
	int GetRank() const;

	/*
	@brief: 전화번호를 반환받는다.
	@pre: set phone number
	@post: none
	*/
	string GetNumber() const;

	/*
	@brief: 이름 반환받는다.
	@pre: set name
	@post: none
	*/
	string GetName() const;

	/*
	@brief: 전문 분야를 반환받는다.
	@pre: set prefer
	@post: none
	*/
	int GetPrefer() const;

	/*
	@brief: 나이를 설정한다.
	@pre: none
	@post: assigned age
	@param: age for assign
	*/
	void SetAge(int inage);

	/*
	@brief: 숙련도를 설정한다.
	@pre: none
	@post: assigned skill
	@param: skill for assign
	*/
	void SetSkill(int inskill);

	/*
	@brief: 희망 일당를 설정한다.
	@pre: none
	@post: assigned money
	@param: money for assign
	*/
	void SetMoney(int inmoney);

	/*
	@brief: 등록 순위를 설정한다.
	@pre: none
	@post: assigned rank
	@param: rank for assign
	*/
	void SetRank(int inrank);

	/*
	@brief: 전화 번호를 설정한다.
	@pre: none
	@post: assigned phone number
	@param: phone number for assign
	*/
	void SetNumber(string innumber);

	/*
	@brief: 이름을 설정한다.
	@pre: none
	@post: assigned name
	@param: name for assign
	*/
	void SetName(string inname);

	/*
	@brief: 전문 분야를 설정한다.
	@pre: none
	@post: assigned prefer
	@param: prefer for assign
	*/
	void SetPrefer(int inprefer);

	/*
	@brief: 구직자의 나이를 키보드로부터 받는다.
	@pre: none
	@post: assign age
	*/
	void SetAgeFromKB();

	/*
	@brief: 구직자의 숙련도를 키보드로부터 받는다.
	@pre: none
	@post: assign skill
	*/
	void SetSkillFromKB();

	/*
	@brief: 구직자의 희망 일당를 키보드로부터 받는다.
	@pre: none
	@post: assign money
	*/
	void SetMoneyFromKB();

	/*
	@brief: 구직자의 전화번호를 키보드로부터 받는다.
	@pre: none
	@post: assign phone number
	*/
	void SetNumberFromKB();

	/*
	@brief: 구직자의 이름을 키보드로부터 받는다.
	@pre: none
	@post: assign Name
	*/
	void SetNameFromKB();

	/*
	@brief: 구직자의 전문 분야를 키보드로부터 받는다.
	@pre: none
	@post: assign Name
	*/
	void SetPreferFromKB();

	/*
	@brief: 구직자의 정보를 키보드로부터 받는다.
	@pre: none
	@post: assign member value
	*/
	void SetRecordFromKB();


	/*
	@brief: 객체의 정보를 파일로부터 받는다.
	@pre: file is valid
	@post: member value is assigned from file data
	@param: valid file for get data
	*/
	int ReadDataFromFile(ifstream& fin);

	/*
	@brief: 객체의 정보를 파일로 내보낸다.
	@pre: set member value
	@post: 파일에 객체의 정보가 쓰여진다.
	@param: valid file
	*/
	int WriteDataToFile(ofstream& fout);

	/*
	@brief: 객체의 정보를 화면에 display
	@pre: set object
	@post: none
	*/
	void DisplayOnScreen();

	/*
	@brief: 입력받은 객체로 현재 객체를 할당
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
	@brief: 두 객체가 같은지 확인
	@pre: set object for compare
	@post: none
	@return: 두 객체의 등록 순위가 같으면 1, 아니면 0을 반환
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