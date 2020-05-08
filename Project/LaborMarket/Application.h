#pragma once
#include "pch.h"

class Application : public Base {
private:
	int a_Command;
public:
	Application() {
		a_Command = -1;
	}									//생성자
	~Application() {}					//소멸자

	/*
	@brief: Display command on screen and get a input from keyboard.
	@pre: none
	@post: set command
	@return: command
	*/
	int GetCommand();

	/*
	@brief: program driver
	@pre: program start
	@post: program finish
	*/
	void Run();

	/*
	@brief: 리스트에 구직자 추가한다.
	@pre: none
	@post: 리스트에 구직자가 추가된다.
	*/
	void AddEmployee();

	/*
	@brief: 등록 순서에 따라 리스트가 display된다.
	@pre: none
	@post: none
	*/
	void DisplayEmployeeByRank();

	/*
	@brief: 이름으로 구직자의 정보를 찾는다.
	@pre: none
	@post: 해당 구직자의 정보가 화면에 display된다.
	*/
	void SearchByName();

	/*
	@brief: 숙련도로 구직자의 정보를 찾는다.
	@pre: none
	@post: 해당 구직자의 정보가 화면에 display된다.
	*/
	void SearchBySkill();

	/*
	@brief: 전문 분야로 구직자의 정보를 찾는다.
	@pre: none
	@post: 해당 구직자의 정보가 화면에 display된다.
	*/
	void SearchByPrefer();

	/*
	@brief: 이름을 찾아 구직자를 차출한다.
	@pre: none
	@post: 구직자의 정보가 display되고 리스트에서 삭제된다.
	*/
	void PickByName();

	/*
	@brief: 조건에 맞는 구직자를 등록 순서로 차출한다.
	@pre: none
	@post: 구직자의 정보가 display되고 리스트에서 삭제된다.
	*/
	void PickEmployee();

	/*
	@brief: 조건에 맞는 구직자를 점수 순서로 차출한다.
	@pre: none
	@post: 구직자의 정보가 display되고 리스트에서 삭제된다.
	*/
	void PickByScore();

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