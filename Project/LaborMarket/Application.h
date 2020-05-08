#pragma once
#include "pch.h"

class Application : public Base {
private:
	int a_Command;
public:
	Application() {
		a_Command = -1;
	}									//������
	~Application() {}					//�Ҹ���

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
	@brief: ����Ʈ�� ������ �߰��Ѵ�.
	@pre: none
	@post: ����Ʈ�� �����ڰ� �߰��ȴ�.
	*/
	void AddEmployee();

	/*
	@brief: ��� ������ ���� ����Ʈ�� display�ȴ�.
	@pre: none
	@post: none
	*/
	void DisplayEmployeeByRank();

	/*
	@brief: �̸����� �������� ������ ã�´�.
	@pre: none
	@post: �ش� �������� ������ ȭ�鿡 display�ȴ�.
	*/
	void SearchByName();

	/*
	@brief: ���õ��� �������� ������ ã�´�.
	@pre: none
	@post: �ش� �������� ������ ȭ�鿡 display�ȴ�.
	*/
	void SearchBySkill();

	/*
	@brief: ���� �о߷� �������� ������ ã�´�.
	@pre: none
	@post: �ش� �������� ������ ȭ�鿡 display�ȴ�.
	*/
	void SearchByPrefer();

	/*
	@brief: �̸��� ã�� �����ڸ� �����Ѵ�.
	@pre: none
	@post: �������� ������ display�ǰ� ����Ʈ���� �����ȴ�.
	*/
	void PickByName();

	/*
	@brief: ���ǿ� �´� �����ڸ� ��� ������ �����Ѵ�.
	@pre: none
	@post: �������� ������ display�ǰ� ����Ʈ���� �����ȴ�.
	*/
	void PickEmployee();

	/*
	@brief: ���ǿ� �´� �����ڸ� ���� ������ �����Ѵ�.
	@pre: none
	@post: �������� ������ display�ǰ� ����Ʈ���� �����ȴ�.
	*/
	void PickByScore();

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